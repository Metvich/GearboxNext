cmake_minimum_required(VERSION 3.20.0)
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
if (CMAKE_WIN32_EXECUTABLE)

  set(rc_icon "${CMAKE_CURRENT_SOURCE_DIR}/resources/rc.rc")

  find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
  add_executable(${PROJECT_NAME} WIN32 ${SOURCES} ${rc_icon})
  target_link_libraries(${PROJECT_NAME} PUBLIC Qt6::Core Qt6::Gui Qt6::Widgets)

  string(REPLACE "lib/cmake/Qt6" "" QT_BASE_DIR ${Qt6_DIR})
  set(OUTPUT_DIR "${CMAKE_BINARY_DIR}/Output")

  #get_target_property(EXECUTABLE_OUTPUT_DIR ${PROJECT_NAME} BINARY_DIR)

  add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E make_directory ${OUTPUT_DIR}
      COMMAND ${CMAKE_COMMAND} -E make_directory ${OUTPUT_DIR}/platforms
      COMMAND ${CMAKE_COMMAND} -E make_directory ${OUTPUT_DIR}/styles
      COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> ${OUTPUT_DIR}/${PROJECT_NAME}.exe
  )
  
  set(OUTPUT_BIN_DLL 
    Qt6Widgets.dll
    Qt6Core.dll
    Qt6Gui.dll
  )
  set(OUTPUT_PLATFORMS_DLL
    qdirect2d.dll
    qminimal.dll
    qoffscreen.dll
    qwindows.dll
  )
  set(OUTPUT_STYLES_DLL
    qmodernwindowsstyle.dll
  )

  function(copy_dll_to_out source_files source_dir destination_dir)
    foreach(var IN LISTS source_files)
      add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy 
        ${source_dir}/${var}
        ${destination_dir}/${var}
      )
    endforeach()
  endfunction()

  copy_dll_to_out("${OUTPUT_BIN_DLL}" ${QT_BASE_DIR}/bin ${OUTPUT_DIR})
  copy_dll_to_out("${OUTPUT_PLATFORMS_DLL}" ${QT_BASE_DIR}/plugins/platforms/ ${OUTPUT_DIR}/platforms)
  copy_dll_to_out("${OUTPUT_STYLES_DLL}" ${QT_BASE_DIR}/plugins/styles/ ${OUTPUT_DIR}/styles)

else()

  find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)
  add_executable(${PROJECT_NAME} ${SOURCES})
  target_link_libraries(${PROJECT_NAME}  PUBLIC Qt6::Core Qt6::Gui Qt6::Widgets)

endif()
