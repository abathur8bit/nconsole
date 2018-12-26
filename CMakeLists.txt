cmake_minimum_required(VERSION 3.0.2)
project(nconsole)

set(CMAKE_CXX_STANDARD 14)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
include_directories("/usr/lib/jvm/java-8-openjdk-amd64/include")
include_directories("/usr/lib/jvm/java-8-openjdk-amd64/include/linux")
include_directories("/Library/Java/JavaVirtualMachines/jdk1.8.0_131.jdk/Contents/Home/include")
include_directories("/Library/Java/JavaVirtualMachines/jdk1.8.0_131.jdk/Contents/Home/include/darwin")
include_directories("/usr/lib/jvm/jdk-8-oracle-arm32-vfp-hflt/include")
include_directories("/usr/lib/jvm/jdk-8-oracle-arm32-vfp-hflt/include/linux")


add_library(nconsole SHARED src/cpp/nconsole.cpp src/cpp/nconsole.h)
target_link_libraries(nconsole ${CURSES_LIBRARIES} )
