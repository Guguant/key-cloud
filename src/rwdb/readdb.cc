/*
 * Copyright (c) 2017 - 2020.
 * GNU General Public License v3.0
 * Sun Yiming <zscandyz[at]gmail[dot]com>
 */

#include "readdb.h"
#include <sqlite3.h>
#include <cstdlib>
#include <cstdio>

namespace rwdb
{
// 读取传感器状态信息
//   select distinct sId, sBuilding, sFloor,sPosition,
//                   sRoom, sOpen,sIP, sDeviceModel from lockrealstatus;
//
void ReadDB::ReadRealStatusInfo(Json::Value &in)
{
    sqlite3 *db;
    int rc;
    rc = sqlite3_open("samlock.db", &db);
    if (rc != SQLITE_OK)
    {
        printf("ERROR opening SQLite DB 'samlock.db': %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(0);
    }

    /*
        * 从 lockrealstatus表中，获取传感器数据
        */
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, "select distinct sroomId,sPosition, sOpen,sIP, sPort, sFacus from lockrealstatus order by sroomId ASC;",
                       -1, &stmt, NULL);

    Json::Value single_sensor_status;
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        single_sensor_status["sroomId"] = (char *)sqlite3_column_text(stmt, 0);
        single_sensor_status["sPosition"] = (char *)sqlite3_column_text(stmt, 1);
        single_sensor_status["sOpen"] = (char *)sqlite3_column_text(stmt, 2);
        single_sensor_status["sIP"] = (char *)sqlite3_column_text(stmt, 3);
        single_sensor_status["sPort"] = (char *)sqlite3_column_text(stmt, 4);
        single_sensor_status["sFacus"] = (char *)sqlite3_column_text(stmt, 5);
        in.append(single_sensor_status);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
} // ReadRealStatusInfo

// 读取用户名和密码信息
void ReadDB::ReadUserId(Json::Value &user_in)
{
    sqlite3 *db;
    int rc;
    rc = sqlite3_open("samlock.db", &db);
    if (rc != SQLITE_OK)
    {
        printf("ERROR opening SQLite DB 'samlock.db': %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(0);
    }

    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, "select distinct username, passwd from user;",
                       -1, &stmt, NULL);

    Json::Value user_id;
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        user_in["username"] = (char *)sqlite3_column_text(stmt, 0);
        user_in["passwd"] = (char *)sqlite3_column_text(stmt, 1);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
} // ReadUserId()

// 读取日志信息
//   select distinct time,info from log 
//
void ReadDB::ReadLog(Json::Value &in)
{
    sqlite3 *db;
    int rc;
    rc = sqlite3_open("samlock.db", &db);
    if (rc != SQLITE_OK)
    {
        printf("ERROR opening SQLite DB 'samlock.db': %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(0);
    }

    /*
     * 从log表中，获取日志数据
     */
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db, "select distinct time,info from log order by time DESC;",
                       -1, &stmt, NULL);

    Json::Value single_sensor_status;
    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW)
    {
        single_sensor_status["time"] = (char *)sqlite3_column_text(stmt, 0);
        single_sensor_status["info"] = (char *)sqlite3_column_text(stmt, 1);
        in.append(single_sensor_status);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
} // ReadRealStatusInfo
} // namespace rwdb