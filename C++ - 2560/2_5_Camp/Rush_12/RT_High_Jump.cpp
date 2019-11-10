/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[605][605],mem[605];
int jump(int now){
    if(now == 2)        return 0;
    if(mem[now]!=-1)    return mem[now];
    int minn = 1e9;
    for(int i=2;i<now;i++)
        minn = min(minn,jump(i)+a[now][i]);
    return mem[now] = minn;
}
int main(){
    int n,ans = 1e9;
    scanf("%d",&n);
    for(int i=1;i<=(2*n);i++)
        for(int j=1;j<=(2*n);j++)
            scanf("%d",&a[i][j]);
    memset(mem,-1,sizeof mem);
    for(int i=2;i<=(2*n)-1;i++)
        ans = min(ans,jump(i)+a[2*n][i]);
    printf("%d\n",ans);
    return 0;
}
