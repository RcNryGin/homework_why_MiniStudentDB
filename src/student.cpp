#include"student.h"
#include<iostream>

Student::Student()
{
    id=0;
    name="";
    age=0;
    score=0.0;
}

Student::Student(int32_t i, string n, int a, double s)
{
    id=i;
    name=n;
    age=a;
    score=s;
}

void Student::display()
{
    cout<<id<<" "<<name<<" "<<age<<" "<<score<<endl;
}
