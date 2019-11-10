/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int mem[110][110][110][110],n,m,ka,kb;
int combi(int a,int b,int c,int d){
    if(mem[a][b][c][d]!=-1) return mem[a][b][c][d];
    if(a==n && b==m)        return mem[a][b][c][d]=1;
    int sum=0;
    if(a<n && c<ka)
        sum+=combi(a+1,b,c+1,0);
    if(b<m && d<kb)
        sum+=combi(a,b+1,0,d+1);
    return mem[a][b][c][d]=sum%MOD;
}
int main(){
    scanf("%d %d %d %d",&n,&m,&ka,&kb);
    memset(mem,-1,sizeof mem);
    printf("%d\n",combi(0,0,0,0));
    return 0;
}
