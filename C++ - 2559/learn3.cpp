#include<iostream>
#include<conio.h>
using namespace std;
struct info{
             char name[20];
             int p;
             int age;
             char c[10];
}x[10];
main(){
       int i;
       for(i=0;i<5;i++){
       cout<<"Name of student "<<i+1<<":";
       cin>>x[i].name;
       cout<<"Password of student "<<i+1<<":";
       cin>>x[i].p;
       cout<<"Age of student "<<i+1<<":";
       cin>>x[i].age;
       cout<<"Class of student "<<i+1<<":";
       cin>>x[i].c;
       }
       for(i=0;i<5;i++){
       if(x[i].age>15){
       cout<<endl<<"Name of student "<<i+1<<":"<<x[i].name<<endl;
       cout<<"Password of student "<<i+1<<":"<<x[i].p<<endl;
       cout<<"Age of student "<<i+1<<":"<<x[i].age<<endl;
       cout<<"Class of student "<<i+1<<":"<<x[i].c<<endl<<endl;
       }
       }
getch();
}
