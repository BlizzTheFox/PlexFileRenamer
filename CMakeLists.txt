cmake_minimum_required(VERSION 3.29)
project(PlexFileRenamer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

set(SOURCE_FILES main.cpp)

# Only do this on Windows
if(WIN32)
        # Create a resource file and add it to the target
        set(APP_RC "${CMAKE_CURRENT_SOURCE_DIR}/version.rc")
endif()

add_executable(PlexFileRenamer main.cpp
        FileManager.cpp
        Formating.cpp
        ${APP_RC}
        )