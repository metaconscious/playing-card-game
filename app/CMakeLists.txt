include_directories(include)

add_subdirectory(src)
target_include_directories(${APP_TARGET_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/lib/base/include)
target_link_libraries(${APP_TARGET_NAME} PRIVATE ${BASE_TARGET_NAME})
