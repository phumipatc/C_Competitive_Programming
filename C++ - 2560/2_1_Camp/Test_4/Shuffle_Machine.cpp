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
A a[110];
int order[110];
int main(){
    int i,n,m,ans=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)   order[i]=i;
    for(i=1;i<=m;i++)   scanf("%d %d",&a[i].x,&a[i].y);
    while(1){
        for(i=1;i<=n;i++)   swap(order[a[i].x],order[a[i].y]);
        int ch=1;
        ans++;
        for(i=1;i<=n;i++)   if(order[i]!=i) ch=0;
        if(ch){
            printf("%d\n",ans);
            return 0;
        }
    }
    return 0;
}
