#include"database.h"
#include<iostream>

DB::DB(const string& fn)
{
    int rc=sqlite3_open(fn.c_str(),&db);
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
        exec(sql);
    }
}
DB::~DB()
{
    if(db)
    {
        sqlite3_close(db);
    }
}
bool DB::exec(const string& sql)
{
    if(!db) return false;
    char* err=nullptr;
    int rc=sqlite3_exec(db,sql.c_str(),nullptr,nullptr,&err);
    if(rc!=SQLITE_OK)
    {
        cerr<<"SQL error: "<<err<<endl;
        sqlite3_free(err);
        return false;
    }
    return true;
}