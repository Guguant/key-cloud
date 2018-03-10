// common data struct
#ifndef SAMLOCK_MYDATA_H_
#define SAMLOCK_MYDATA_H_

// This struct is the smart lock device infomation.
struct DeviceInfo
{
    char roomId[10];    // room's id number.
    char position[30];  // room's position.
    char open[6];       // the on, off, wrong status.
    char ip[21];        // the device IP.
    char port[6];       // the IP's port.
    char facus[2];      // if user have facused on the room.
}; // DeviceInfo

// LOG
struct Log
{
    char logTime[20];   // Log time
    char logInfo[100];  // Log content
}; // Log
#endif // SAMLOCK_MYDATA_H_