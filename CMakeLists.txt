cmake_minimum_required(VERSION 3.5.0)
project(app)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

find_package(PkgConfig REQUIRED)
# GTKmm 4 (GTK for C++, C++ binding/adaptation)
# sudo apt install libgtkmm-4.0-dev # in Debian GNU/Linux
# pacman -S mingw-w64-x86_64-gtkmm4 # in MSYS+MINGW
pkg_check_modules(GTKMM gtkmm-4.0)

include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

file(GLOB SOURCE_FILES code/*.cpp)
add_executable(${CMAKE_PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${CMAKE_PROJECT_NAME} ${GTKMM_LIBRARIES})

# CMake is gonna read the 'CMakeLists.txt' file located under 'example':
#add_subdirectory(example) # https://stackoverflow.com/questions/68782979/how-to-create-a-cmakelists-txt-for-a-gtkmm-application
