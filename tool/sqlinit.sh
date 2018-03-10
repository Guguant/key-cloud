#!/bin/bash

# ========================================
# Author: Andy
# e-mail: guguant@yahoo.com
# Date  : 2017-11-06
# Script: create sql databases and tables.
# ========================================

# 1. 创建samlock.db
# 创建lockrealstatus表
# 记录所有接入监控系统的传感器状态
sqlite3 samlock.db "CREATE TABLE "lockrealstatus" (
    sroomId TEXT NOT NULL,
    sPosition TEXT,
    sOpen TEX
    sIP TEXT NOT NULL,
    sPort TEXT NOT NULL,
    PRIMARY KEY(sroomId)
    )";

# 创建lockrealfacus表
# 记录用户关注的传感器状态
sqlite3 samlock.db "CREATE TABLE "lockrealfacus" (
    sId TEXT NOT NULL,
    sBuilding INTEGER,
    sFloor INTEGER,
    sPosition TEXT,
    sRoom INTEGER,
    sOpen TEXT,
    sIP TEXT NOT NULL,
    sDeviceModel TEXT,
    PRIMARY KEY(sId)
    )";

# newestversion table
sqlite3 samlock.db "CREATE TABLE "newestversion" (
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

# 【user】 table
sqlite3 samlock.db "CREATE TABLE "user" (
    username TEXT NOT NULL UNIQUE,
    passwd TEXT NOT NULL UNIQUE,
    PRIMARY KEY(username)
    )";
