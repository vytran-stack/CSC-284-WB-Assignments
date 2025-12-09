cmake_minimum_required(VERSION 3.20)
project(Unit10_ChatroomClient C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Đường dẫn tới thư mục PDCurses (nằm cùng cấp với main.cpp)
set(PDC_DIR ${CMAKE_SOURCE_DIR}/PDCurses-3.9)

# In ra để chắc chắn đường dẫn đúng (cậu xem ở tab CMake khi reload)
message(STATUS "PDC_DIR = ${PDC_DIR}")

# Lấy source PDCurses
file(GLOB PDC_COMMON_SOURCES
        ${PDC_DIR}/pdcurses/*.c
        ${PDC_DIR}/common/*.c
)

file(GLOB PDC_WINCON_SOURCES
        ${PDC_DIR}/wincon/*.c
)

message(STATUS "Found common sources: ${PDC_COMMON_SOURCES}")
message(STATUS "Found wincon sources: ${PDC_WINCON_SOURCES}")

# Source C++ của cậu
set(SOURCES
        main.cpp
        Window.cpp
        RoomList.cpp
        MessageArea.cpp
        InputArea.cpp
        ChatClientUI.cpp
)

add_executable(Unit10_ChatroomClient
        ${SOURCES}
        ${PDC_COMMON_SOURCES}
        ${PDC_WINCON_SOURCES}
)

# Include path để #include <curses.h>
target_include_directories(Unit10_ChatroomClient PRIVATE
        ${PDC_DIR}
        ${PDC_DIR}/wincon
)

if (WIN32)
    target_compile_definitions(Unit10_ChatroomClient PRIVATE
            PDC_WIDE
            _CRT_SECURE_NO_WARNINGS
    )
endif()
