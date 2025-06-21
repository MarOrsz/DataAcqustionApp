#pragma once
#include <string>


struct sqlite3;

class DbStore
{
    private:
    sqlite3* db;
    

    public:
    DbStore();
    ~DbStore();

    void store(std::string tableName, std::string columnName, float value);
};