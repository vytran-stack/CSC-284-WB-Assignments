cmake_minimum_required(VERSION 4.0)
project(Unit_08_01_UserProfileUpdater)

set(CMAKE_CXX_STANDARD 20)

add_executable(Unit_08_01_UserProfileUpdater main.cpp
        FileUtils.cpp
        FileUtils.h
        JsonTransformer.cpp
        JsonTransformer.h
        DirectoryProcessor.cpp
        DirectoryProcessor.h)
