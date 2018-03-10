#include "writedb.h"
#include <sqlite3.h>
#include <cstdlib>
#include <cstdio>
#include <cstring>
namespace rwdb
{
bool WriteDB::WriteNewDeviceToDB(struct DeviceInfo &deviceinfo)
{
    sqlite3 *db;
    int rc;
    rc = sqlite3_open("samlock.db", &db);
    if (rc != SQLITE_OK)
    {
        printf("ERROR opening SQLite DB 'samlock.db': %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return false;
    }

    /*
     * 将新增加的设备信息加入到lockrealstatus表中
     */
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db,  "insert into lockrealstatus(sroomId,sPosition, sOpen,sIP, sPort, sFacus)"
                            " values(?1, ?2, ?3, ?4, ?5, ?6);", -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, deviceinfo.roomId,  -1, SQLITE_STATIC);     
    sqlite3_bind_text(stmt, 2, deviceinfo.position,-1, SQLITE_STATIC);     
    sqlite3_bind_text(stmt, 3, deviceinfo.open,    -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, deviceinfo.ip,      -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, deviceinfo.port,    -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, deviceinfo.facus,   -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        printf("ERROR inserting data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return false;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return true;
} // WriteNewDeviceToDB

bool WriteDB::WriteLogToDB(struct Log &log)
{
    sqlite3 *db;
    int rc;
    rc = sqlite3_open("samlock.db", &db);
    if (rc != SQLITE_OK)
    {
        printf("ERROR opening SQLite DB 'samlock.db': %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return false;
    }

    /*
     * 将新生产的日志信息加入到log表中
     */
    sqlite3_stmt *stmt;
    sqlite3_prepare_v2(db,  "insert into log(time,info)"
                            " values(?1, ?2);", -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, log.logTime, -1, SQLITE_STATIC);     
    sqlite3_bind_text(stmt, 2, log.logInfo, -1, SQLITE_STATIC);

    rc = sqlite3_step(stmt);
    if (rc != SQLITE_DONE) {
        printf("ERROR inserting data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return false;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);
    return true;
} // WriteLogToDB
} // namespace rwdb