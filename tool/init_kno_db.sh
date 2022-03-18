#!/bin/bash
# ========================================
# Author: Andy
# e-mail: zscandyz[at]gmail[dot]com
# Date  : 2017-11-06
# Script: create sql databases and tables.
# ========================================

# At first, create the database kno.db
# Then, create lockrealstatus.table (record all sensors' status)
sqlite3 kno.db "CREATE TABLE "lockrealstatus" (
    sroomId TEXT NOT NULL,
    sPosition TEXT,
    sOpen TEXT,
    sIP TEXT NOT NULL,
    sPort TEXT NOT NULL,
    sFacus INTEGER,
    PRIMARY KEY(sroomId)
    )";

# create newestversion.table
sqlite3 kno.db "CREATE TABLE "newestversion" (
    pNewFunciton TEXT,
    pVersionHistory TEXT,
    pVersionCurrent TEXT NOT NULL UNIQUE,
    pVersionReleaseTime TEXT,
    pPublishCompany TEXT,
    pSize TEXT,
    pCompatibility TEXT,
    pLanguage TEXT,
    pDeveloper TEXT,
    pPrivacyPolicy TEXT,
    PRIMARY KEY(pVersionCurrent)
    )";

# create user.table
sqlite3 kno.db "CREATE TABLE "user" (
    username TEXT NOT NULL UNIQUE,
    passwd TEXT NOT NULL UNIQUE,
    PRIMARY KEY(username)
    )";

# create log.table
sqlite3 kno.db "CREATE TABLE "log" (
    time NUMRIC,
    info TEXT,
    PRIMARY KEY(time)
    )";