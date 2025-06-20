
add_library(DataProcessorLib STATIC
    src/DataProcessor.cpp
)

target_include_directories(DataProcessorLib
                            PUBLIC inc)

target_link_libraries(DataProcessorLib PUBLIC DataQueueLib)