#ifndef DATABASE_H
#define DATABASE_H
#include<sqlite3.h>
#include<string>
using namespace std;

class DB
{
public:
    DB(const string& filename);
    ~DB();
    bool exec(const string& sql);
private:
    sqlite3* db;
};
#endif
