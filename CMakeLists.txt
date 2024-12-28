cmake_minimum_required(VERSION 3.20.0)
project(GearboxNext VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES ON)

function(set_with_prefix list_name prefix)
    set(prefixed_list)

    foreach(item IN LISTS ARGN)
        list(APPEND prefixed_list "${prefix}${item}")
    endforeach()

    set(${list_name} ${prefixed_list} PARENT_SCOPE)
endfunction()

set_with_prefix(SOURCES src/
    main.cpp
    MainWindow.cpp
    GearBoxPanel.cpp
    GearsPanel.cpp
)

source_group(TREE "${CMAKE_CURRENT_SOURCE_DIR}" FILES ${SOURCES})

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

if (WIN32)

  set(rc_icon "${CMAKE_CURRENT_SOURCE_DIR}/resources/rc.rc")

  string(REPLACE "lib/cmake/Qt6" "" QT_BASE_DIR ${Qt6_DIR})

  set_with_prefix(OUTPUT_BIN_DLL ${QT_BASE_DIR}/bin/
    Qt6Widgets.dll
    Qt6Core.dll
    Qt6Gui.dll
  )

  set_with_prefix(OUTPUT_PLATFORMS_DLL ${QT_BASE_DIR}/plugins/platforms/
    qdirect2d.dll
    qminimal.dll
    qoffscreen.dll
    qwindows.dll
  )

  set_with_prefix(OUTPUT_STYLES_DLL ${QT_BASE_DIR}/plugins/styles/
    qmodernwindowsstyle.dll
  )
  
  add_executable(${PROJECT_NAME} WIN32 ${SOURCES} ${rc_icon})

  install(TARGETS ${PROJECT_NAME} DESTINATION .)
  install(FILES ${OUTPUT_BIN_DLL} DESTINATION .)
  install(FILES ${OUTPUT_PLATFORMS_DLL} DESTINATION platforms)
  install(FILES ${OUTPUT_STYLES_DLL} DESTINATION styles)

else()

  add_executable(${PROJECT_NAME} ${SOURCES})

  install(TARGETS ${PROJECT_NAME} DESTINATION bin)
  install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/resources/Logo.ico DESTINATION icons)

endif()

target_link_libraries(${PROJECT_NAME} PUBLIC Qt6::Core Qt6::Gui Qt6::Widgets)
target_include_directories(${PROJECT_NAME} PUBLIC include)
