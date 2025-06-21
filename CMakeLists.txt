cmake_minimum_required(VERSION 3.21)

project(DataAcqusitionApp VERSION 0.0)

# ====== CXX STANDARD ======
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# ====== SUBDIRECTORIES ======
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/app/TcpServer)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/app/WebSocketClient)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/app/DataQueue)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/app/DataProcessor)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/app/DbStore)



# ====== EXECUTABLE ======
add_executable(DataAcqusitionApp ${CMAKE_CURRENT_SOURCE_DIR}/app/main.cpp)

# ====== LIBRARY LINK - INTERNAL ======
target_link_libraries(DataAcqusitionApp 
                    PRIVATE TcpServerLib
                    PRIVATE WebSocketClientLib
                    PRIVATE DataQueueLib
                    PRIVATE DataProcessorLib
                    PRIVATE DbStoreLib)

# ====== LIBRARY LINK - EXTERNAL ======