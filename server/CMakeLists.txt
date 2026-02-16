cmake_minimum_required(VERSION 3.24)
project(Server) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(X11 REQUIRED)
find_library(XEXT_LIB NAMES Xext REQUIRED)
find_library(XTST_LIB NAMES Xtst REQUIRED) 
find_package(JPEG REQUIRED)
find_package(Protobuf REQUIRED)

set(
    SRC_FILES
    src/main.cpp
    
    ../common/protocal.pb.h
    ../common/protocal.pb.cc 
    
    src/LosJpeg/LosJpeg.h
    src/LosJpeg/LosJpeg.cpp

    src/LosImage/LosImage.h
    src/LosImage/LosImage.cpp

    src/LosBuf/LosBuf.cpp
    src/LosBuf/LosBuf.h

    src/LosTcpServer/LosTcpServer.h
    src/LosTcpServer/LosTcpServer.cpp

    src/LosErrorSet/LosErrorSet.h
    src/LosErrorSet/LosErrorSet.cpp

    ../common/logger.h
    ../common/logger.cpp
)

add_executable(Server ${SRC_FILES})

target_include_directories(Server PRIVATE 
    ${X11_INCLUDE_DIR}
    ${Protobuf_INCLUDE_DIRS}   
    ${CMAKE_CURRENT_SOURCE_DIR}/../common
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(Server PRIVATE
    protobuf::libprotobuf     
    JPEG::JPEG          
    ${X11_LIBRARIES}    
    ${XEXT_LIB}        
    ${XTST_LIB}         
    pthread             
)