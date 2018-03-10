/*
 * Copyright (c) 2017 An.AI Inc.
 *  
 *
 * License boilerplate.
 *
 * Sun Yiming. Email: hi@anai.co
 */

#ifndef SAMLOCK_RWDB_READDB_H_
#define SAMLOCK_RWDB_READDB_H_

#include <json/json.h>

/* 禁止使用拷贝构造函数和赋值操作的宏 */
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
TypeName(const TypeName &);            \
void operator=(const TypeName &)

namespace rwdb
{
class ReadDB
{
  public:
    explicit ReadDB() {}
    virtual ~ReadDB() {}

    //【REAL STATUS】
    // This function is to read all sensors' real status
    // from lockrealstatus.table in samlock.db.
    // input: json
    // output:json using &
    void ReadRealStatusInfo(Json::Value & in);

    // 【USERNAME AND PASSWD】
    // Here it read username and passwd to validate user.
    void ReadUserId(Json::Value & user_in);

    // 【LOG】
    void ReadLog(Json::Value &in);

  private:
    DISALLOW_COPY_AND_ASSIGN(ReadDB);
}; // class ReadDB
}// namesapce rwdb
#endif // SAMLOCK_RWDB_READDB_H_