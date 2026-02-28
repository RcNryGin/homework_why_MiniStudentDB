#include<bits/stdc++.h>
using namespace std;

void showMenu()
{
 cout<<"===== Student DB ====="<<endl;
 cout<<"1. Add student"<<endl;
 cout<<"2. Delete student"<<endl;
 cout<<"3. Update student"<<endl;
 cout<<"4. List students"<<endl;
 cout<<"0. Exit"<<endl;
}

int main()
{
 int choice;
 while(true)
 {
  showMenu();
  cin>>choice;
  if(choice==0) break;
 }
 return 0;
}
