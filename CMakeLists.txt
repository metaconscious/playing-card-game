cmake_minimum_required(VERSION 3.21)
project(PlayingCardGame VERSION 0.38.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED 20)

# -Weffc++ not in use
# since "error: base class ‘class std::enable_shared_from_this<_Ty>’ has accessible non-virtual destructor"
# would be thrown by compiler
# set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wsign-conversion -Werror -pedantic-errors")

set(UTIL_TARGET_NAME ${PROJECT_NAME}Util)
set(BASE_TARGET_NAME ${PROJECT_NAME}Base)
set(APP_TARGET_NAME ${PROJECT_NAME}App)

add_subdirectory(ext)
add_subdirectory(lib)
add_subdirectory(app)

option(ENABLE_TEST off)

if (ENABLE_TEST)
    add_subdirectory(test)
endif ()
