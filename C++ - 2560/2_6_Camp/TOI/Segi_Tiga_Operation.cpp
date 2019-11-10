/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mem[260][260][3],mark[260][260],n;
char str[260];
void divide(int l,int r){
    if(mem[1][n][0])    return ;
    if(mark[l][r])      return ;
    if(l == r)          return ;
    mark[l][r] = 1;
    for(int k=l;k<r;k++){
        divide(l,k);
        divide(k+1,r);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(!mem[l][k][i] || !mem[k+1][r][j])    continue;
                if(i==0){
                    if(j==0)  mem[l][r][2]=1;
                    if(j==1)  mem[l][r][1]=1;
                    if(j==2)  mem[l][r][0]=1;
                }
                if(i==1){
                    if(j==0)  mem[l][r][2]=1;
                    if(j==1)  mem[l][r][1]=1;
                    if(j==2)  mem[l][r][1]=1;
                }
                if(i==2){
                    if(j==0)  mem[l][r][1]=1;
                    if(j==1)  mem[l][r][2]=1;
                    if(j==2)  mem[l][r][1]=1;
                }
                if(mem[1][n][0])
                    return ;
            }
        }
    }
}
int main(){
    int q = 20;
    while(q--){
        scanf("%d %s",&n,str+1);
        for(int i=1;i<=n;i++)
            mark[i][i] = 1,mem[i][i][str[i]-'0'] = 1;
        divide(1,n);
        if(mem[1][n][0])    printf("yes\n");
        else                printf("no\n");
        memset(mem,0,sizeof mem);
        memset(mark,0,sizeof mark);
    }
    return 0;
}
