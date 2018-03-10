/*
 * Copyright (c) 2017 An.AI Inc.
 * All right reserved.
 *
 * License boilerplate.
 *
 * Sun Yiming. Email: hi@anai.co
 */

#include <json/json.h>
#include <mongoose/mongoose.h>
#include "timer/timerclock.h"

// 数据读写类
#include "rwdb/readdb.h"
#include "rwdb/writedb.h"

#include "transform.h"
#include "mydata.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

static const char *s_http_port = "8888";
static struct mg_serve_http_opts s_http_server_opts;

// ssi call
static void handle_ssi_call(struct mg_connection *nc, const char *param)
{
    if (strcmp(param, "username") == 0)
    {
        mg_printf_html_escape(nc, "%s", "username");
    }
    else if (strcmp(param, "passwd") == 0)
    {
        mg_printf_html_escape(nc, "%s", "passwd");
    }
    else if (strcmp(param, "roomid") == 0)
    {
        mg_printf_html_escape(nc, "%s", "roomid");
    }
    else if (strcmp(param, "position") == 0)
    {
        mg_printf_html_escape(nc, "%s", "position");
    }
    else if (strcmp(param, "open") == 0)
    {
        mg_printf_html_escape(nc, "%s", "open");
    }
    else if (strcmp(param, "IP") == 0)
    {
        mg_printf_html_escape(nc, "%s", "IP");
    }
    else if (strcmp(param, "port") == 0)
    {
        mg_printf_html_escape(nc, "%s", "port");
    }
    else if (strcmp(param, "facus") == 0)
    {
        mg_printf_html_escape(nc, "%s", "facus");
    }
    else
    {
        ;
    }
} // handle_ssi_call

// handle_real_status()
// Function: display sensors's real status that on or off.
// Example: a sensor statu in JSON Format.
//      {
//          "sroomId":   "101",
//          "sPosition": "6教南",
//          "sOpen" :    "on",
//          "sIP":       "192.168.0.1",
//          “sPort”:     "15113"
//          "sFacus":    "1" // 1 like, 0 unlike
//      }
static void handle_real_status(struct mg_connection *nc)
{
    // read data from samlock.db database.
    Json::Value sensor_status_list;
    rwdb::ReadDB read_status;
    read_status.ReadRealStatusInfo(sensor_status_list);
    string trans = "";
    JsonToString(sensor_status_list, trans);

    // get current time
    samtimer::Timer *TimeCatch = new samtimer::Timer;
    TimeCatch->set_current_time();
    string current_time = "";
    TimeCatch->GetStringTime(current_time);
    delete TimeCatch;

    // DEBUG
    printf("\033[33m[%s] INFO\033[0m\ncall function handle_real_status() to "
           "get sensors' status.\n",
           current_time.c_str());
    printf("####################\n");
    printf("%s\n", trans.c_str());

    // SEND DATA
    mg_printf(nc, "%s", "HTTP/1.1 200 OK\r\nTransfer-Encoding: chunked\r\n\r\n");
    mg_printf_http_chunk(nc, "%s", trans.c_str());
    mg_send_http_chunk(nc, "", 0);
} // handle_real_status()

// handle_generate_analysis_table()
// Function:
//         It analyze Sensor Status Info Datebase and
//         return the result.
static void handle_generate_analysis_table(struct mg_connection *nc)
{
    // sensor real status infomation
    Json::Value device_status_list;
    rwdb::ReadDB read_device;
    read_device.ReadRealStatusInfo(device_status_list);

    // get current time
    samtimer::Timer *TimeCatch = new samtimer::Timer;
    TimeCatch->set_current_time();
    string current_time = "";
    TimeCatch->GetStringTime(current_time);
    delete TimeCatch;

    // 【表格 title + time + data】
    Json::Value data_table;
    data_table["title"] = "杭州电子科技大学 6 教";
    data_table["time"] = current_time;
    data_table["data"].append(device_status_list);

    string trans = "";
    JsonToString(data_table, trans);

    // DEBUG
    printf("\033[33m[%s] INFO\033[0m\n call function handle_generate_analysis_table() "
           "to generate the analysis table.\n",
           current_time.c_str());

    // SEND DATA
    mg_printf(nc, "%s", "HTTP/1.1 200 OK\r\nTransfer-Encoding: chunked\r\n\r\n");
    mg_printf_http_chunk(nc, "%s", trans.c_str());
    mg_send_http_chunk(nc, "", 0);
} // handle_generate_analysis_table

// handle_login()
// Function: When users have login in web,
//           this check in the username and passwd.
static void handle_login(struct mg_connection *nc, struct http_message *hm)
{
    // get username and passwd from web.
    char username[100] = {""};
    char passwd[100] = {""};
    mg_get_http_var(&hm->body, "username", username, sizeof(username));
    mg_get_http_var(&hm->body, "passwd",   passwd,   sizeof(passwd));

    // validate the username and passwd.
    // if succeed, Success's value is equal to 1.
    Json::Value right_user;
    rwdb::ReadDB read_user;
    read_user.ReadUserId(right_user);

    // Check in username and passwd.
    int success = 0;
    if (strcmp(username, right_user["username"].asString().c_str()) == 0 &&
        strcmp(passwd, right_user["passwd"].asString().c_str()) == 0)
    {
        success = 1;
        printf("\033[33m%s login Succeed\033[0m\n", username);
    }
    else
    {
        printf("\033[33m%s login Failed\033[0m\n", username);
    }
    Json::Value reback;
    reback["success"] = success;
    string trans = "";
    JsonToString(reback, trans);

    // SEND DATA.
    mg_printf(nc, "%s", "HTTP/1.1 200 OK\r\nTransfer-Encoding: chunked\r\n\r\n");
    mg_printf_http_chunk(nc, "%s", trans.c_str());
    mg_send_http_chunk(nc, "", 0);
} // handle_login

// handle_add_device()
// Function: add a new device.
static void handle_add_device(struct mg_connection *nc, struct http_message *hm)
{
    // CATCH DATA FROM WEB REQUEST
    DeviceInfo newdevice = {"", "", "off", "","","0"};
    mg_get_http_var(&hm->body, "roomid", newdevice.roomId, sizeof(newdevice.roomId));
    mg_get_http_var(&hm->body, "position", newdevice.position, sizeof(newdevice.position));
    mg_get_http_var(&hm->body, "IP", newdevice.ip, sizeof(newdevice.ip));
    mg_get_http_var(&hm->body, "port", newdevice.port, sizeof(newdevice.port));
    mg_get_http_var(&hm->body, "facus", newdevice.facus, sizeof(newdevice.facus));

    // DEBUG
    printf("\033[33m%s\033[0m\n","add new device");
    printf("@ the new device infomation follow as:\n");
    printf("{\n");
    printf("  %-10s %s\n", "position", newdevice.position);
    printf("  %-10s %s\n", "roomid",   newdevice.roomId);
    printf("  %-10s %s\n", "ip",       newdevice.ip);
    printf("  %-10s %s\n", "port",     newdevice.port);
    printf("  %-10s %s\n", "facus",    newdevice.facus);
    printf("}\n");

    // write struct newdevice into DB
    bool issuccess = true;
    rwdb::WriteDB write_data;
    issuccess = write_data.WriteNewDeviceToDB(newdevice);

    int backcode = 0;
    if (issuccess)
    {
        backcode = 1;

        // WRITE LOG : new add a device.
        Log log = {"", ""};
        
        // get current time
        samtimer::Timer *  TimeCatch = new samtimer::Timer;
        TimeCatch->set_current_time();
        string current_time = "";
        TimeCatch->GetStringTime(current_time);
        delete TimeCatch;

        sprintf(log.logTime, "%s", current_time.c_str());
        sprintf(log.logInfo, "added a new device, roomid-%s ip-%s", newdevice.roomId, newdevice.ip);
        issuccess = write_data.WriteLogToDB(log);        
    }

    Json::Value reback;
    reback["success"] = backcode;
    string trans = "";
    JsonToString(reback, trans);

    // SEND DATA
    mg_printf(nc, "%s", "HTTP/1.1 200 OK\r\nTransfer-Encoding: chunked\r\n\r\n");
    mg_printf_http_chunk(nc, "%s", trans.c_str());
    mg_send_http_chunk(nc, "", 0);
} // handle_add_device

// handle_display_log()
// Function: display Log info.
// Example: Log described in Json Format.
//      {
//          "time", 2018-01-11 21:06:57
//          "log",  added a new device, roomid-101 ip-000.000.000.000
//      }
static void handle_display_log(struct mg_connection *nc)
{
    // read data from samlock.db database.
    Json::Value log_lists;
    rwdb::ReadDB readlog;
    readlog.ReadLog(log_lists);
    string trans = "";
    JsonToString(log_lists, trans);

    // get current time
    samtimer::Timer *TimeCatch = new samtimer::Timer;
    TimeCatch->set_current_time();
    string current_time = "";
    TimeCatch->GetStringTime(current_time);
    delete TimeCatch;

    // DEBUG
    printf("\033[33m[%s] INFO\033[0m\ncall function handle_display_log() to "
           "display log lists.\n",
           current_time.c_str());
    printf("####################\n");
    printf("%s\n", trans.c_str());

    // SEND DATA
    mg_printf(nc, "%s", "HTTP/1.1 200 OK\r\nTransfer-Encoding: chunked\r\n\r\n");
    mg_printf_http_chunk(nc, "%s", trans.c_str());
    mg_send_http_chunk(nc, "", 0);
} // handle_display_log()

// handle event
// Function: This is URL GET or POST request model,
//           all url is handled here.
static void ev_handler(struct mg_connection *nc, int ev, void *ev_data)
{
    struct http_message *hm = (struct http_message *)ev_data;
    switch (ev)
    {
    case MG_EV_HTTP_REQUEST:
        ////////////////////////////////////////
        ///> 【1】login.shtml
        /// Login page.
        if (mg_vcmp(&hm->uri, "/api/login.json") == 0)
        {
            handle_login(nc, hm);
        }
        
        /////////////////////////////////////////
        ///> 【2】 status.shtml
        /// This is the status Page used to show sensers' real status data.
        else if (mg_vcmp(&hm->uri, "/real-status.json") == 0)
        {
            handle_real_status(nc);
        }

        //////////////////////////////////////////
        ///> 【3】analysis.shtml
        /// This is the analysis page used to generate real data table.
        else if (mg_vcmp(&hm->uri, "/api/analysis/result.json") == 0)
        {
            handle_generate_analysis_table(nc);
        }

        //////////////////////////////////////////
        ///> 【4】configure.shtml
        /// To get the list of device monitored.
        else if (mg_vcmp(&hm->uri, "/api/monitorlist.json") == 0)
        {
            
            handle_real_status(nc);
        }

        //////////////////////////////////////////
        ///> 【5】configure.shtml
        /// Add a new device.
        else if (mg_vcmp(&hm->uri, "/api/addDeviceInfo.json") == 0)
        {
            handle_add_device(nc, hm);
        }

        /////////////////////////////////////////
        ///> 【6】system.shtml
        /// To display the system LOG.
        else if (mg_vcmp(&hm->uri, "/api/log.json") == 0)
        {
            // TODO
            handle_display_log(nc);
        }

        //////////////////////////////////////////
        ///> 【7】This is the static web page
        ///  when web have no request, it display
        ///  the current page to users.
        else
        {
            mg_serve_http(nc, hm, s_http_server_opts);
        }
        break;
    case MG_EV_SSI_CALL:
        handle_ssi_call(nc, (char *)ev_data);
        break;
    default:
        break;
    }
} // event_handler

int main(int argc, char *argv[])
{
    struct mg_mgr mgr;
    struct mg_connection *nc;
    cs_stat_t st;

    mg_mgr_init(&mgr, NULL);

    nc = mg_bind(&mgr, s_http_port, ev_handler);
    if (nc == NULL)
    {
        fprintf(stderr, "Cannot bind to %s.\n", s_http_port);
        exit(1);
    }

    // Set up HTTP server parameters
    mg_set_protocol_http_websocket(nc);

    // web root directory
    s_http_server_opts.document_root = "web_root";

    if (mg_stat(s_http_server_opts.document_root, &st) != 0)
    {
        fprintf(stderr, "%s", "Cannot find web_root directory, exiting.\n");
        exit(1);
    }

    printf("Starting web server on port %s\n", s_http_port);
    for (;;)
    {
        mg_mgr_poll(&mgr, 1000);
    }
    mg_mgr_free(&mgr);

    return 0;
} // main