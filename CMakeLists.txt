cmake_minimum_required(VERSION 3.0)

project(CryptoChat)
find_package(ZLIB REQUIRED)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)

# --------------COMPILER SPECIFIC---------------- #

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
	set(CMAKE_CXX_FLAGS "-O3 -Wall -flto -DNDEBUG")

elseif (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
	set(CMAKE_CXX_FLAGS "-O3 -Wall -flto -DNDEBUG -s")

elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
#	Nobody Uses Windows Anyways ;)
#	set(CMAKE_CXX_FLAGS "/O1 /strip /Wall")
	MESSAGE("For MSVC you need to Compile Manually !!")
endif()

# ----------------------------------------------- #

add_executable(CryptoChat "main.cpp")
target_link_libraries(CryptoChat ZLIB)
