find_package(Boost REQUIRED COMPONENTS system beast)

add_library(WebSocketClientLib STATIC src/WebSocketClient.cpp)

target_include_directories(WebSocketClientLib PUBLIC inc)

if(WIN32)
    target_link_libraries(WebSocketClientLib PUBLIC Ws2_32)
endif()

target_link_libraries(WebSocketClientLib PUBLIC Boost::system Boost::beast)