cmake_minimum_required(VERSION 3.24)
project(ClientQt LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "E:/Qt/6.10.2/msvc2022_64")
set(protobuf_DIR "E:/vcpkg/vcpkg/installed/x64-windows/share/protobuf")
set(absl_DIR "E:/vcpkg/vcpkg/installed/x64-windows/share/absl")
set(utf8_range_DIR "E:/vcpkg/vcpkg/installed/x64-windows/share/utf8_range")

find_package(protobuf CONFIG REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Network)

qt_standard_project_setup()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC OFF) 

set(APP_SOURCES
    src/main.cpp
    src/MainWindow.cpp
    src/MainWindow.h
)

set(FORMS
    src/MainWindow.ui
)

qt_wrap_ui(UI_HEADERS ${FORMS})

qt_add_executable(ClientQt
    MANUAL_FINALIZATION
    ${APP_SOURCES}
    ${PROTO_SOURCES}  
    ${UI_HEADERS}
)

if(MSVC)
    target_compile_options(ClientQt PRIVATE /utf-8 /W4 /wd4828)
endif()

target_link_libraries(ClientQt 
    PRIVATE 
    Qt6::Widgets
    Qt6::Core 
    Qt6::Network
    protobuf::libprotobuf  
)

target_include_directories(ClientQt PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_BINARY_DIR} 
)

qt_finalize_executable(ClientQt)
