/*
 * Copyright (c) 2017 - 2022.
 * GNU General Public License v3.0
 * Sun Yiming <zscandyz[at]gmail[dot]com>
 */

#ifndef KNO_RWDB_WRITEDB_H_
#define KNO_RWDB_WRITEDB_H_

#include "../mydata.h"
#include <json/json.h>

/* 禁止使用拷贝构造函数和赋值操作的宏 */
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
TypeName(const TypeName &);            \
void operator=(const TypeName &)

namespace rwdb
{
class WriteDB
{
  public:
    explicit WriteDB() {}
    virtual ~WriteDB() {}

    // write new device data to database.
    bool WriteNewDeviceToDB(struct DeviceInfo &deviceinfo);

    // write log data to database.
    bool WriteLogToDB(struct Log &log);
  private:
    DISALLOW_COPY_AND_ASSIGN(WriteDB);
}; // class WriteDB
}// namesapce rwdb
#endif // KNO_RWDB_WRITEDB_H_