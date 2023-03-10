cmake_minimum_required(VERSION 2.8)
project(Hello_git)

set(SOURCE_EXE src/main.cpp)
add_executable(Hello_git ${SOURCE_EXE})

set(SOURCE_LIB src/moduleOne.cpp src/Constrants.cpp)
add_library(moduleOne STATIC ${SOURCE_LIB})
add_library(Constrants STATIC ${SOURCE_LIB})

add_subdirectory(include)
target_include_directories(Hello_git PUBLIC include)

target_link_libraries(Hello_git moduleOne Constrants) 
