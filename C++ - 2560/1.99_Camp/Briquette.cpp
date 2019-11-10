/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<bits/stdc++.h>
using namespace std;
int p[10100],n,m,mark[10100];
int froot(int i){
    if(p[i]==i) return i;
    return p[i]=froot(p[i]);
}
int main()
{
    int i,j,ans=0,first;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)   p[i]=i;
    while(n--){
        scanf("%d",&j);
        if(j==0)    ans++;
        else{
            scanf("%d",&first);
            mark[first]=1;
        }
        while(j-->1){
            scanf("%d",&i);
            mark[i]=1;
            p[froot(i)]=p[froot(first)];
        }
    }
    for(i=1;i<=m;i++)
        if(p[i]==i && mark[i]==1)
            ans++;
    printf("%d\n",ans-1);
    return 0;
}
