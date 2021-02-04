/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int l,r;
};
A a[200010];
int dis[200010],dif[200010];
int main(){
    int n,h,idx;
    scanf("%d %d",&n,&h);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a[i].l,&a[i].r);
        dis[i] = dis[i-1]+(a[i].r-a[i].l);
    }
    for(int i=2;i<=n;i++)
        dif[i] = dif[i-1]+(a[i].l-a[i-1].r);
    // for(int i=1;i<=n;i++)
    //     printf("%d ",dis[i]);
    // printf("\n");
    // for(int i=1;i<=n;i++)
    //     printf("%d ",dif[i]);
    // printf("\n");
    int maxx = 0;
    for(int i=1;i<=n;i++){
        idx = lower_bound(dif+1,dif+n+1,dif[i]+h)-dif-1;
        // printf("%d %d %d\n",i,idx,dis[idx]-dis[i-1]+h);
        maxx = max(maxx,dis[idx]-dis[i-1]+h);
    }
    printf("%d\n",maxx);
	return 0;
}