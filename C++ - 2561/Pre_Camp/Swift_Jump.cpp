/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int pos[300000],mx[100000],my[100000],dp[300000];
struct A{
    int x,y,w,id;
    bool operator<(const A &o)const{
        if(x!=o.x)      return x<o.x;
        else            return y<o.y;
    }
};
A a[300300];
int main(){
    int n,b;
    scanf("%d %d",&n,&b);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].w);
        a[i].id = i;
    }
    memset(mx,-1,sizeof mx);
    memset(my,-1,sizeof my);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        pos[a[i].id] = i;
    mx[a[pos[1]].x] = a[pos[1]].w;
    my[a[pos[1]].y] = a[pos[1]].w;
    for(int i = pos[1]+1;i<=n;i++){
        dp[a[i].id] = max(mx[a[i].x],my[a[i].y]);
        if(dp[a[i].id] < b)	continue;
        dp[a[i].id]+=a[i].w-b;
        if(dp[a[i].id] >= b && mx[a[i].x]<dp[a[i].id])	mx[a[i].x]=dp[a[i].id];
        if(dp[a[i].id] >= b && my[a[i].y]<dp[a[i].id])	my[a[i].y]=dp[a[i].id];
        if(a[i].id == n)	break;
    }
    printf("%d\n",dp[n]);
}
