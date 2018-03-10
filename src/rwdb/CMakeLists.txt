cmake_minimum_required(VERSION 3.5)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

ADD_EXECUTABLE(rwdb_test rw_test/rw_test.cc
                         readdb.cc writedb.cc)
TARGET_LINK_LIBRARIES(rwdb_test sqlite3 
                     ${PROJECT_SOURCE_DIR}/lib/libjsoncpp.a)