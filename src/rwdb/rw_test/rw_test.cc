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