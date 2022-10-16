include_directories(include)

add_subdirectory(src)
target_include_directories(${BASE_TARGET_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/lib/utility/include)
target_link_libraries(${BASE_TARGET_NAME} PUBLIC ${UTIL_TARGET_NAME})
