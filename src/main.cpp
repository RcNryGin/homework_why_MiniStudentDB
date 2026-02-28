#include<bits/stdc++.h>
#include"database.h"
#include"student.h"
using namespace std;

Database db("data/student.db");

void showMenu()
{
    cout<<"===== Student DB ====="<<endl;
    cout<<"1. Add student"<<endl;
    cout<<"2. Delete student"<<endl;
    cout<<"3. Update student"<<endl;
    cout<<"4. List students"<<endl;
    cout<<"0. Exit"<<endl;
}

void addStudent()
{
    string name;
    int age;
    double score;
    cout<<"Enter name: ";
    cin>>name;
    cout<<"Enter age: ";
    cin>>age;
    cout<<"Enter score: ";
    cin>>score;
    string sql="INSERT INTO student (name,age,score) VALUES ('"+name+"',"+to_string(age)+","+to_string(score)+");";
    if(db.execute(sql))
        cout<<"Student added successfully."<<endl;
    else
        cout<<"Failed to add student."<<endl;
}

void deleteStudent()
{
    int id;
    cout<<"Enter student id to delete: ";
    cin>>id;
    string sql="DELETE FROM student WHERE id="+to_string(id)+";";
    if(db.execute(sql))
        cout<<"Student deleted successfully."<<endl;
    else
        cout<<"Failed to delete student."<<endl;
}

void updateStudent()
{
    int id;
    cout<<"Enter student id to update: ";
    cin>>id;
    cout<<"Enter new name: ";
    string name;
    cin>>name;
    cout<<"Enter new age: ";
    int age;
    cin>>age;
    cout<<"Enter new score: ";
    double score;
    cin>>score;
    string sql="UPDATE student SET name='"+name+"',age="+to_string(age)+",score="+to_string(score)+" WHERE id="+to_string(id)+";";
    if(db.execute(sql))
        cout<<"Student updated successfully."<<endl;
    else
        cout<<"Failed to update student."<<endl;
}

void listStudents()
{
    sqlite3* sqlite;
    if(sqlite3_open("data/student.db",&sqlite)!=SQLITE_OK)
    {
        cout<<"Cannot open database."<<endl;
        return;
    }
    const char* sql="SELECT * FROM student;";
    sqlite3_stmt* stmt;
    if(sqlite3_prepare_v2(sqlite,sql,-1,&stmt,nullptr)!=SQLITE_OK)
    {
        cout<<"Query failed."<<endl;
        sqlite3_close(sqlite);
        return;
    }
    cout<<"ID\tName\tAge\tScore"<<endl;
    while(sqlite3_step(stmt)==SQLITE_ROW)
    {
        int id=sqlite3_column_int(stmt,0);
        const char* name=(const char*)sqlite3_column_text(stmt,1);
        int age=sqlite3_column_int(stmt,2);
        double score=sqlite3_column_double(stmt,3);
        cout<<id<<"\t"<<name<<"\t"<<age<<"\t"<<score<<endl;
    }
    sqlite3_finalize(stmt);
    sqlite3_close(sqlite);
}

int main()
{
    int choice;
    while(true)
    {
        showMenu();
        cout<<"Enter choice: ";
        cin>>choice;
        if(choice==0) break;
        else if(choice==1) addStudent();
        else if(choice==2) deleteStudent();
        else if(choice==3) updateStudent();
        else if(choice==4) listStudents();
        else cout<<"Invalid choice."<<endl;
    }
    return 0;
}
