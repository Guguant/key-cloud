/*
 * Copyright (c) 2017 - 2020.
 * GNU General Public License v3.0
 * Sun Yiming <zscandyz[at]gmail[dot]com>
 */

#include "transform.h"

// Transform data with json type to string  
void JsonToString(const Json::Value & json_in, string & string_out)
{
    Json::StreamWriterBuilder wbuilder;
    wbuilder["indentation"] = "  ";
    string_out = Json::writeString(wbuilder, json_in);
}