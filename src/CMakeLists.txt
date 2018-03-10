cmake_minimum_required(VERSION 3.5)

# include finding path
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

AUX_SOURCE_DIRECTORY(timer/ TIMER)
AUX_SOURCE_DIRECTORY(rwdb/  RWDB)
AUX_SOURCE_DIRECTORY(./ MAIN)

# output path for binary file
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
ADD_EXECUTABLE(sam server.cc ${TIMER} ${RWDB} ${MAIN})
TARGET_LINK_LIBRARIES(sam sqlite3
                          ${PROJECT_SOURCE_DIR}/lib/libmongoose.a
                          ${PROJECT_SOURCE_DIR}/lib/libjsoncpp.a
                          )

ADD_SUBDIRECTORY(timer)
ADD_SUBDIRECTORY(sensor)
ADD_SUBDIRECTORY(rwdb)