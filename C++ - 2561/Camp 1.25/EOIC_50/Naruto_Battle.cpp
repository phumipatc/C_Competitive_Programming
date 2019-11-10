/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    char c;
    int idx;
    bool operator < (const A&o) const{
        return c<o.c;
    }
};
A a[100100];
char str[100100],naruto[100100],sasuke[100100];
int mark[100100];
int main(){
    int n,now = 0,num = 0;
    scanf("%d %s",&n,str);
    for(int i=0;i<n;i++)
        a[i].c = str[i],a[i].idx = i;
    sort(a,a+n);
    printf("%s %s\n",naruto,sasuke);
	return 0;
}
