/*
 * Copyright (c) 2017 - 2022.
 * GNU General Public License v3.0
 * Sun Yiming <zscandyz[at]gmail[dot]com>
 */

#ifndef KNO_TRANSFORM_H_
#define KNO_TRANSFORM_H_

#include <json/json.h>
#include <string>
using namespace std;

// Here this transforms Json data to String.
void JsonToString(const Json::Value & json_in, string & string_out);

#endif // SAM_TRANSFORM_H_