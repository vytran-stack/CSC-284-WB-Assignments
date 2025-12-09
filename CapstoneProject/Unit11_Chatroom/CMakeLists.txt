cmake_minimum_required(VERSION 3.26)
project(Unit11_Chatroom C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ChatServer
        server/ChatServer.cpp
)

add_executable(ChatClient
        client/ChatClient.cpp
)

set(PDC_DIR "${CMAKE_SOURCE_DIR}/PDCurses-3.9")

file(GLOB PDC_COMMON_SOURCES
        "${PDC_DIR}/pdcurses/*.c"
        "${PDC_DIR}/common/*.c"
)
file(GLOB PDC_WINCON_SOURCES
        "${PDC_DIR}/wincon/*.c"
)

add_executable(ChatClientCurses
        client/main.cpp
        client/ChatClientUI.cpp
        client/Window.cpp
        client/RoomList.cpp
        client/InputArea.cpp
        client/MessageArea.cpp
        ${PDC_COMMON_SOURCES}
        ${PDC_WINCON_SOURCES}
)


target_include_directories(ChatClientCurses PRIVATE
        "${PDC_DIR}"
        "${PDC_DIR}/wincon"
)


if (WIN32)
    target_link_libraries(ChatServer       ws2_32)
    target_link_libraries(ChatClient       ws2_32)
    target_link_libraries(ChatClientCurses ws2_32)

    target_compile_definitions(ChatClientCurses PRIVATE
            PDC_WIDE
            _CRT_SECURE_NO_WARNINGS
    )
endif()
