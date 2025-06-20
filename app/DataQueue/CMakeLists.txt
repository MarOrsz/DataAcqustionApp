
add_library(DataQueueLib STATIC
    src/DataQueue.cpp
)

target_include_directories(DataQueueLib
                            PUBLIC inc)