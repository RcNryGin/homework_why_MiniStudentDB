#include"database.h"
#include<iostream>

Database::Database(const string& filename)
{
    int rc=sqlite3_open(filename.c_str(),&db);
    if(rc!=SQLITE_OK)
    {
        cerr<<"Cannot open database: "<<sqlite3_errmsg(db)<<endl;
        db=nullptr;
    }
    else
    {
        const char* sql="CREATE TABLE IF NOT EXISTS student("
                        "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                        "name TEXT NOT NULL,"
                        "age INTEGER,"
                        "score REAL);";
        execute(sql);
    }
}

Database::~Database()
{
    if(db)
    {
        sqlite3_close(db);
    }
}

bool Database::execute(const string& sql)
{
    if(!db) return false;
    char* errMsg=nullptr;
    int rc=sqlite3_exec(db,sql.c_str(),nullptr,nullptr,&errMsg);
    if(rc!=SQLITE_OK)
    {
        cerr<<"SQL error: "<<errMsg<<endl;
        sqlite3_free(errMsg);
        return false;
    }
    return true;
}
