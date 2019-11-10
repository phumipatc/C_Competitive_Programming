/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int pos[300000],mx[100000],my[100000],mic[300000];
struct info{
    int x,y,a,p;
    bool operator<(const info &o)const{
        if(x!=o.x)      return x<o.x;
        else            return y<o.y;
    }
};
info arr[300300];
int main(){
    int n,b,i;
    scanf("%d %d",&n,&b);
    for(i=1;i<=n;i++){
        scanf("%d %d %d",&arr[i].x,&arr[i].y,&arr[i].a);
        arr[i].p=i;
    }
    memset(mx,-1,sizeof mx);
    memset(my,-1,sizeof my);
    sort(arr+1,arr+n+1);
    for(i=1;i<=n;i++)
        pos[arr[i].p]=i;
    mx[arr[pos[1]].x]=arr[pos[1]].a;
    my[arr[pos[1]].y]=arr[pos[1]].a;
    for(i=pos[1]+1;i<=n;i++){
        mic[arr[i].p]=max(mx[arr[i].x],my[arr[i].y]);
        if(mic[arr[i].p] < b)   continue;
        mic[arr[i].p]+=arr[i].a;
        mic[arr[i].p]-=b;
        if(mic[arr[i].p] >= b && mx[arr[i].x]<mic[arr[i].p]) mx[arr[i].x]=mic[arr[i].p];
        if(mic[arr[i].p] >= b && my[arr[i].y]<mic[arr[i].p]) my[arr[i].y]=mic[arr[i].p];
        if(arr[i].p==n) break;
    }
    printf("%d\n",mic[n]);
}
