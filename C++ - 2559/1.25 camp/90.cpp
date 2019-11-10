/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include <cstdio>
#include <list>
#include <iostream>
#include <cstring>
using namespace std;
list<int> l;
list<int>::iterator cur,cur2;
int main()
{
    int n,num;
    char a[50];
    l.push_front(999);
    cur = l.begin();
    scanf("%d",&n);
    while(n--){
        scanf(" %s",a);
        if(!strcmp(a,"head")){
            cur = l.begin();
        }
        else if(!strcmp(a,"next")){
            cur2=cur;
            cur2++;
            if(cur2!=l.end()){
                cur++;
            }
        }
        else if(!strcmp(a,"tail")){
            cur = l.end();
            cur--;
        }
        else if(!strcmp(a,"add")){
            scanf("%d",&num);
            cur2=cur;
            cur2++;
            if(cur2==l.end()){
                l.push_back(num);
            }
            else{
                cur++;
                l.insert(cur,num);
                cur--; cur--;
            }
        }
        else if(!strcmp(a,"remove")){
            cur2=cur;
            cur2++;
            if(cur2!=l.end()){
                cur++;
                cur = l.erase(cur);
                cur--;
            }
        }
        else if(!strcmp(a,"call")){
            cout<< *cur << " ";
        }
        else if(!strcmp(a,"list")){
            for(;cur!=l.end();cur++)
                cout<< *cur << " ";
            cur--;
        }
    }
    return 0;
}
