
add_library(TcpServerLib STATIC
    src/TcpServer.cpp
)

target_include_directories(TcpServerLib
                            PUBLIC inc)

if(WIN32)
    target_compile_definitions(TcpServerLib PRIVATE TcpServerLib_EXPORTS)
    target_link_libraries(TcpServerLib PUBLIC Ws2_32)
endif()