/*
    TASK:Printer
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<cstdio>
#include<list>
#include<string>
#include<iostream>
using namespace std;
list<string> l;
list<string>::iterator cur,cur2;
string b;
int main()
{
    int n;
    char a;
    l.push_front("xxx");
    cur=l.begin();
    scanf("%d",&n);
    while(n--){
        scanf(" %c",&a);
        if(a=='i'){
            cin>>b;
            cur2=cur;
            cur2++;
            if(cur2==l.end()){
                l.push_back(b);
                cur++;
            }else{
                cur++;
                l.insert(cur,b);
                cur--;
            }
        }else if(a=='l'){
            if(cur!=l.begin()){
                cur--;
            }
        }else if(a=='r'){
            cur2=cur;
            cur2++;
            if(cur2!=l.end()){
                cur++;
            }
        }else if(a=='b'){
            if(cur!=l.begin()){
                cur=l.erase(cur);
                cur--;
            }
        }else if(a=='d'){
            cur2=cur;
            cur2++;
            if(cur2!=l.end()){
                cur++;
                cur=l.erase(cur);
                cur--;
            }
        }
    }
        cur=l.begin();
        for(cur++;cur!=l.end();cur++)
            cout<<*cur<<endl;
return 0;
}
