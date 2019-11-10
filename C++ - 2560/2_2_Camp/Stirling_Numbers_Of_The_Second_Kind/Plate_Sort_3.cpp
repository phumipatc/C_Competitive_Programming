/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 9871
using namespace std;
int mem[1100][1100];
int stirling(int n,int k){
    if(n==0 && k==0)    return 1;
    if(n==0 || k==0)    return 0;
    if(mem[n][k]!=-1)   return mem[n][k];
    return mem[n][k]=((k*stirling(n-1,k))+stirling(n-1,k-1))%MOD;
}
int main(){
    int q;
    memset(mem,-1,sizeof mem);
    scanf("%d",&q);
    while(q--){
        int n,k;
        scanf("%d %d",&n,&k);
        printf("%d\n",stirling(n,k));
    }
    return 0;
}
