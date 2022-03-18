/*
 * Copyright (c) 2017 - 2022.
 * GNU General Public License v3.0
 * Sun Yiming <zscandyz[at]gmail[dot]com>
 */

#include "../readdb.h"
#include <json/json.h>

#include <string>
#include <cstdio>
using namespace std;

int main()
{
    Json::Value out;
    rwdb::ReadDB real_status;
    real_status.ReadRealStatusInfo(out);

    Json::StreamWriterBuilder wbuilder;
    wbuilder["indentation"] = "  ";
    string trans = "";
    trans = Json::writeString(wbuilder, out);
    
    printf("%s\n", trans.c_str());
    return 0;
}