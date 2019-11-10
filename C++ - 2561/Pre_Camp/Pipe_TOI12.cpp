/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
pair<int ,int > a[15005];
int dis[15005];
int main(){
    int n,k,minn,now;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i].x,&a[i].y);
    for(int i=1;i<=n;i++)   dis[i] = 1e9;
    for(int i=1;i<n;i++){
        minn = 1e9;
        for(int j=i+1;j<=n;j++){
            dis[j] = min(dis[j],abs(a[i].x-a[j].x)+abs(a[i].y-a[j].y));
            if(dis[j]<minn){
                minn = dis[j];
                now = j;
            }
        }
        swap(dis[i+1],dis[now]);
        swap(a[i+1],a[now]);
    }
    int ans = 0;
    sort(dis+1,dis+n+1);
    for(int i=1;i<=n-k;i++) ans+=dis[i];
    printf("%d\n",ans);
    return 0;
}
