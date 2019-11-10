/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1000010];
vector<char > ans[1000010];
int l[1000010],r[1000010];
int main(){
    gets(a+1);
    int len = strlen(a+1),countt = 0;
    for(int i=1;i<=len;i++){
        if(a[i] == '.')
            countt++;
        if(a[i] == ' ') a[i] = '_';
    }
    for(int i=2;i<=countt;i++)
        l[i] = i-1;
    l[1] = countt;
    for(int i=1;i<countt;i++)
        r[i] = i+1;
    r[countt] = 1;
    int now = 1;
    for(int i=1;i<=len;i++){
        ans[now].push_back(a[i]);
        if(a[i] == '.'){
            r[l[now]] = r[now];
            l[r[now]] = l[now];
        }
        now = r[now];
    }
    for(int i=1;i<=countt;i++){
        for(auto x:ans[i])
            printf("%c",x);
        printf("\n");
    }
	return 0;
}