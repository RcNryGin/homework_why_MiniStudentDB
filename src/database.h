#ifndef DATABASE_H
#define DATABASE_H

#include<sqlite3.h>
#include<string>
using namespace std;

class Database
{
public:
    Database(const string& filename);
    ~Database();
    bool execute(const string& sql);
private:
    sqlite3* db;
};

#endif
