#include "DbStore.h"
#include <iostream>
#include <sqlite3.h>
#include <string>


DbStore::DbStore()
{
    int rc = sqlite3_open("MEASURE.db", &db);
    if (rc != SQLITE_OK) 
    {
        sqlite3_close(db);
        return;
    }

    const char* sql = R"(CREATE TABLE IF NOT EXISTS measurements (  id INTEGER PRIMARY KEY,
                                                                    value REAL,
                                                                    created_at TEXT DEFAULT CURRENT_TIMESTAMP);)";
    rc = sqlite3_exec(db, sql, 0, 0, 0);
    if (rc != SQLITE_OK) 
    {
        std::cout << "Could not create the initial table" << std::endl;
    }
    else std::cout << "Table measurements exists in MEAS db" << std:: endl;


}

DbStore::~DbStore()
{
    sqlite3_close(db);
}

void DbStore::store(std::string tableName, std::string columnName, float value)
{
    std::string sql = "INSERT INTO measurements (" + columnName + ") VALUES (" + std::to_string(value) + ");";
    
    if (sqlite3_exec(db, sql.c_str(), 0, 0, 0) != SQLITE_OK) {
        std::cerr << "Insert failed: " << std::endl;
}
}
