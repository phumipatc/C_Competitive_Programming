/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int a,b;
};
A p[50005];
int mark[1005][1005];
int main(){
    int n,m,countt,ans,ans2;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&p[i].a,&p[i].b);
        mark[p[i].a][p[i].b] = mark[p[i].b][p[i].a] = 1;
    }
    ans = ans2 = 0;
    for(int i=1;i<m;i++){
        for(int j=i+1;j<=m;j++){
            if(p[i].a == p[j].a || p[i].a == p[j].b)    continue;
            if(p[i].b == p[j].a || p[i].b == p[j].b)    continue;
            countt=2;
            if(mark[p[i].a][p[j].a])    countt++;
            if(mark[p[i].a][p[j].b])    countt++;
            if(mark[p[i].b][p[j].a])    countt++;
            if(mark[p[i].b][p[j].b])    countt++;
            if(countt == 5) ans++;
            if(countt == 6) ans2++;
        }
    }
    printf("%d\n",(ans/2)+(ans2/3));
    return 0;
}
