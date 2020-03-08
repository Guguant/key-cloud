#!/bin/bash
# ========================================
# Author: Andy
# e-mail: zscandyz[at]gmail[dot]com
# Date  : 2017-11-06
# Script:
#   This script inserts test datas into tables, 
#       including:{
#           lockrealstatus: 传感器实时状态表,
#           lockrealfacus:  用户关注的传感器设备实时状态表
#       };
# ========================================

# This code snippest inserts test data into 
# table lockrealstatus in samlock.db.
sqlite3 samlock.db \
"INSERT INTO lockrealstatus (sId,sBuilding,sFloor,sPosition,sRoom,sOpen,sIP,sDeviceModel) \
                     VALUES ('1001',6,1,'南',101, 'on', '192.168.0.1', '海思')" \
"INSERT INTO lockrealstatus (sId,sBuilding,sFloor,sPosition,sRoom,sOpen,sIP,sDeviceModel) \
                     VALUES ('1012',6,1,'南',104, 'on', '192.168.1.1', 'NVIDIA')" \
"INSERT INTO lockrealstatus (sId,sBuilding,sFloor,sPosition,sRoom,sOpen,sIP,sDeviceModel) \
                     VALUES ('1005',6,3,'中',301, 'off', '192.168.1.1', 'Intel')" \
"INSERT INTO lockrealstatus (sId,sBuilding,sFloor,sPosition,sRoom,sOpen,sIP,sDeviceModel) \
                     VALUES ('1019',6,5,'南',501, 'off', '192.168.10.11', '三星')";

# This code snippest inserts testdata into
# table lockrealfacus in samlock.db
sqlite3 samlock.db \
"INSERT INTO lockrealfacus (sId,sBuilding,sFloor,sPosition,sRoom,sOpen,sIP,sDeviceModel) \
                     VALUES ('1005',6,3,'中',301, 'off', '192.168.1.1', 'Intel')" \
"INSERT INTO lockrealfacus (sId,sBuilding,sFloor,sPosition,sRoom,sOpen,sIP,sDeviceModel) \
                     VALUES ('1001',6,1,'南',101, 'on', '192.168.0.1', '海思')";

# newestversion.table
sqlite3 samlock.db \
"INSERT INTO newestversion (pNewFunciton, pVersionHistory, pVersionCurrent, \
        pVersionReleaseTime, pPublishCompany, pSize, pCompatibility, \
        pLanguage, pDeveloper, pPrivacyPolicy) \
        VALUES ('- 实时读取传感器数据 - 优化web端界面',\
                'history.shtml', \
                '1.1.20', \
                '2017-10-30',\
                'Anaian.com Co.,Ltd', \
                '1.3M',\
                'Chrome | firefox',\
                '简体中文',\
                'www.sam.anaian.com',\
                'terms')";

# 【user】 table test data
sqlite3 samlock.db "INSERT INTO user (username, passwd) VALUES ('admin', 'admin')"
