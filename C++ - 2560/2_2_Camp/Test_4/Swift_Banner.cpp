/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int banner[310][310],mem[310][310];
int place(int l,int r){
    if(mem[l][r]!=-1)   return mem[l][r];
    if(l==r)            return banner[l][r];
    int maxx=-1;
    for(int i=l;i<r;i++){
        maxx=max(maxx,place(l,i)+place(i+1,r)+banner[l][r]);
    }
    return mem[l][r]=maxx;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        int st,en;
        scanf("%d %d",&st,&en);
        banner[st][en]++;
    }
    memset(mem,-1,sizeof mem);
    printf("%d",m-place(1,n));
    return 0;
}
