cmake_minimum_required(VERSION 3.19.0)
project(EasyGearBox VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_WIN32_EXECUTABLE ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)
#add_compile_options(-O2)

set(HEADERS
    include/MainWindow.h
    include/GearBoxPanel.h
    include/GearsPanel.h
)

set(SOURCES
    ${HEADERS}
    src/main.cpp
    src/MainWindow.cpp
    src/GearBoxPanel.cpp
    src/GearsPanel.cpp
)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

#set(rc_icon "${CMAKE_CURRENT_SOURCE_DIR}/rc.rc") 

find_package(Qt6 REQUIRED COMPONENTS Widgets)
add_executable(${PROJECT_NAME} ${SOURCES}) #${rc_icon})
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)
