cmake_minimum_required(VERSION 3.24)
project(LosServerProject) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(X11 REQUIRED)
find_library(XEXT_LIB NAMES Xext REQUIRED)
find_library(XTST_LIB NAMES Xtst REQUIRED) 
find_package(JPEG REQUIRED)
find_package(Protobuf REQUIRED)           

set(
    SRC_FILES
    src/main.cpp
)

add_executable(Server ${SRC_FILES})

target_include_directories(Server PRIVATE 
    include
    ${X11_INCLUDE_DIR}
)

target_link_libraries(Server PRIVATE
    ${Protobuf_LIBRARIES}                   
    JPEG::JPEG          
    ${X11_LIBRARIES}    
    ${XEXT_LIB}        
    ${XTST_LIB}         
    pthread             
)
