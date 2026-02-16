cmake_minimum_required(VERSION 3.24)
project(Client LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "E:/Qt/6.10.2/msvc2022_64")
set(protobuf_DIR "E:/vcpkg/vcpkg/installed/x64-windows/share/protobuf")
set(absl_DIR "E:/vcpkg/vcpkg/installed/x64-windows/share/absl")
set(utf8_range_DIR "E:/vcpkg/vcpkg/installed/x64-windows/share/utf8_range")

find_package(protobuf CONFIG REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Network)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC OFF) 

set(APP_SOURCES
    src/main.cpp
    src/MainWindow.cpp
    src/MainWindow.h
    src/MainWindow.ui

    src/component/InitPage/InitPage.cpp
    src/component/InitPage/InitPage.h
    src/component/InitPage/InitPage_style.h
    src/component/InitPage/InitPage.ui


    src/component/ConnectPage/ConnectPage.cpp
    src/component/ConnectPage/ConnectPage_style.h
    src/component/ConnectPage/ConnectPage.h
    src/component/ConnectPage/ConnectPage.ui


    src/component/SettingPage/SettingPage.cpp
    src/component/SettingPage/SettingPage.h
    src/component/SettingPage/SettingPage_style.h
    src/component/SettingPage/SettingPage.ui


    src/component/TopWidget/TopWidget.cpp
    src/component/TopWidget/TopWidget.h

    src/net/NetManage.h
    src/net/NetManage.cpp

    ../common/protocal.pb.h
    ../common/protocal.pb.cc
    ../common/logger.h
    ../common/logger.cpp

)

add_executable(Client
    ${APP_SOURCES}
)

if(MSVC)
    target_compile_options(Client PRIVATE /utf-8 /W4 /wd4828)
endif()

target_link_libraries(Client 
    PRIVATE 
    Qt6::Widgets
    Qt6::Core 
    Qt6::Network
    protobuf::libprotobuf  
)

target_include_directories(Client PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR} 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/component
    ${CMAKE_CURRENT_SOURCE_DIR}/src/net
    ${CMAKE_CURRENT_SOURCE_DIR}/../common
    ${CMAKE_CURRENT_BINARY_DIR}  
)

