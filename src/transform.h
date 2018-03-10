// 格式转换类

#ifndef SAMLOCK_TRANSFORM_H_
#define SAMLOCK_TRANSFORM_H_

#include <json/json.h>
#include <string>
using namespace std;

// Here this transforms Json data to String.
void JsonToString(const Json::Value & json_in, string & string_out);

#endif // SAM_TRANSFORM_H_