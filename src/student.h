#ifndef STUDENT_H
#define STUDENT_H

#include<cstdint>
#include<string>
using namespace std;

class Student
{
public:
    Student();
    Student(int32_t id, string name, int age, double score);
    void display();
    int32_t id;
    string name;
    int age;
    double score;
};

#endif
