#!/bin/bash
# ========================================
# Author: Andy
# e-mail: zscandyz[at]gmail[dot]com
# Date  : 2017-11-06, First Summit
# Update: 2022-03-19, Opt details
# Script:
#   This script inserts test datas into tables,
#       including:{
#           lockrealstatus.table: sensor real statu table
#           newestversion.table: the newest version table
#           user.table: users' info table (username+passwd)
#       };
# ========================================

# lockrealstatus.table
sqlite3 kno.db \
"INSERT INTO lockrealstatus (sroomId, sPosition, sOpen, sIP, sPort, sFacus) \
                     VALUES ('101', '6教南', 'off', '192.168.1.1', '8000', 1)" \
"INSERT INTO lockrealstatus (sroomId, sPosition, sOpen, sIP, sPort, sFacus) \
                     VALUES ('102', '6教南', 'on', '192.168.1.2', '8000', 0)" \
"INSERT INTO lockrealstatus (sroomId, sPosition, sOpen, sIP, sPort, sFacus) \
                     VALUES ('103', '6教北', 'wrong', '192.168.3.1', '8000', 1)" \
"INSERT INTO lockrealstatus (sroomId, sPosition, sOpen, sIP, sPort, sFacus) \
                     VALUES ('201', '6教中', 'on', '192.168.6.1', '8000', 0)" \
"INSERT INTO lockrealstatus (sroomId, sPosition, sOpen, sIP, sPort, sFacus) \
                     VALUES ('208', '6教南', 'off', '192.168.5.4', '8000', 0)" \
"INSERT INTO lockrealstatus (sroomId, sPosition, sOpen, sIP, sPort, sFacus) \
                     VALUES ('302', '6教中', 'off', '192.168.1.23', '8000', 0)" \
"INSERT INTO lockrealstatus (sroomId, sPosition, sOpen, sIP, sPort, sFacus) \
                     VALUES ('304', '6教南', 'off', '192.168.5.1', '8000', 1)";

# newestversion.table
sqlite3 kno.db \
"INSERT INTO newestversion (pNewFunciton, pVersionHistory, pVersionCurrent, \
        pVersionReleaseTime, pPublishCompany, pSize, pCompatibility, \
        pLanguage, pDeveloper, pPrivacyPolicy) \
        VALUES ('- real read sensors status - opt web pages',\
                'history.shtml', \
                '1.1.20', \
                '2017-10-30',\
                'Anaian.com Co.,Ltd', \
                '1.3M',\
                'Chrome | firefox',\
                'EN',\
                'www.kno.anaian.com',\
                'terms')";

# user.table
sqlite3 kno.db "INSERT INTO user (username, passwd) VALUES ('admin', 'admin')";

# log.table
sqlite3 kno.db \
        "INSERT INTO log (time, info) VALUES ('2022-03-19 00:41:40', 'added a new device, roomid-304 ip-192.168.5.1')"  \
        "INSERT INTO log (time, info) VALUES ('2022-03-19 00:43:16', 'added a new device, roomid-208 ip-192.168.5.4')";
