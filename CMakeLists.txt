cmake_minimum_required(VERSION 3.19.0)
project(GearboxNext VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

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

set(rc_icon "${CMAKE_CURRENT_SOURCE_DIR}/resources/rc.rc")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
add_executable(${PROJECT_NAME} ${SOURCES} ${rc_icon})
target_link_libraries(${PROJECT_NAME}  PUBLIC Qt6::Core Qt6::Gui Qt6::Widgets)

if (WIN32)

set(OUTPUT_DIR "${CMAKE_BINARY_DIR}/Output/${CMAKE_BUILD_TYPE}")
set(DLL_DIR "${CMAKE_SOURCE_DIR}/lib/")
set(EXE_NAME "${PROJECT_NAME}.exe")

get_target_property(EXECUTABLE_OUTPUT_DIR ${EXE_NAME} BINARY_DIR)

add_custom_command(TARGET ${EXE_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory ${OUTPUT_DIR}
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${DLL_DIR}
        ${OUTPUT_DIR}/
        COMMAND ${CMAKE_COMMAND} -E copy
        $<TARGET_FILE:${EXE_NAME}>
        ${OUTPUT_DIR}/${EXE_NAME}
)

add_custom_command(TARGET MyExecutable POST_BUILD
    # Создайте целевую директорию, если она не существует
    COMMAND ${CMAKE_COMMAND} -E make_directory ${COPY_DIR}
    # Скопируйте .exe файл в указанную папку
    
)

endif()