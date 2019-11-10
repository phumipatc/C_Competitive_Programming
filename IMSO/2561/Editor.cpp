/*
    TASK:
    AUTHOR: Phumipat C.
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
list<string> listt;
list<string>::iterator it,it2;
string str;
int main()
{
    int n;
    char cmd;
    str = "start";
    listt.push_front(str);
    it = listt.begin();
    scanf("%d",&n);
    while(n--){
        scanf(" %c",&cmd);
        if(cmd=='i'){
            cin >> str;
            it2 = it;
            it2++;
            if(it2==listt.end()){
                listt.push_back(str);
                it++;
            }else{
                it++;
                listt.insert(it,str);
                it--;
            }
        }else if(cmd=='l'){
            if(it!=listt.begin()){
                it--;
            }
        }else if(cmd=='r'){
            it2 = it;
            it2++;
            if(it2!=listt.end()){
                it++;
            }
        }else if(cmd=='b'){
            if(it!=listt.begin()){
                it = listt.erase(it);
                it--;
            }
        }else if(cmd=='d'){
            it2=it;
            it2++;
            if(it2!=listt.end()){
                it++;
                it = listt.erase(it);
                it--;
            }
        }
    }
    it = listt.begin();
    it++;
    for(;it!=listt.end();it++)
        cout << *it << " ";
}
