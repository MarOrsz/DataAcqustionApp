
find_package(unofficial-sqlite3 CONFIG REQUIRED)


add_library(DbStoreLib STATIC
    src/DbStore.cpp
)

target_include_directories(DbStoreLib
                            PUBLIC inc)

target_link_libraries(DbStoreLib PRIVATE unofficial::sqlite3::sqlite3)

