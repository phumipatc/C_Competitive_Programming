/*
    TASK:Kosean Song
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
map<string ,int > a;
char b[400],*c;
int main(){
    int n;
    gets(b);
    sscanf(b,"%d",&n);
    while(n--){
        gets(b);
        c=strtok(b," ");
        while(c!=NULL){
            a[c]++;
            c=strtok(NULL," ");
        }
        int ch=0;
        for(map<string, int>::iterator it=a.begin();it!=a.end();it++){
                if(a[it->first]>=4){
                    ch=1;
                    break;
                }
        }
        a.clear();
        printf((ch)?"yes\n":"no\n");
    }
return 0;
}
