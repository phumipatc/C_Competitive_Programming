/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int weight[5100],mem[5100][5100],n,k;
int ans(int now,int choose){
    int maxx=-1;
    if(now>n)                   return 0;
    if(choose==0)               return mem[now][0]=0;
    if(mem[now][choose]!=-1)    return mem[now][choose];
    //printf("%d %d\n",now,choose);
    for(int i=0;i<choose;i++)
        maxx=max(maxx,ans(now*2,i)+ans((now*2)+1,(choose-1)-i));
    return mem[now][choose]=maxx+weight[now];
}
int main(){
    int maxx=-1,i;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
        scanf("%d",&weight[i]);
    memset(mem,-1,sizeof mem);
    for(i=1;i<=n;i++)
        maxx=max(maxx,ans(i,k));
    printf("%d\n",maxx);

    return 0;
}
