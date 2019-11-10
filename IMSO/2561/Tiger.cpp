/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y;
};
A fire[1100],tiger[1100];
map<int,int> mapp;
int main(){
    int n,m,minn,ans = 0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&fire[i].x,&fire[i].y);
    for(int i=1;i<=m;i++)
        scanf("%d %d",&tiger[i].x,&tiger[i].y);
    for(int i=1;i<=m;i++){
        minn = 1e9;
        for(int j=1;j<=n;j++)
            minn = min(minn,abs(tiger[i].x-fire[j].x)+abs(tiger[i].y-fire[j].y));
        mapp[minn]++;
        ans = max(ans,mapp[minn]);
    }
    printf("%d\n",ans);
    return 0;
}
