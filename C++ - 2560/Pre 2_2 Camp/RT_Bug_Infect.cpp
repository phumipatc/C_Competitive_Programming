/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long p[1600][1600],temp[1600],ans[1600];
int main(){
    long long n,m,k,i,j,l;
    scanf("%lld %lld %lld",&k,&n,&m);
    for(i=1;i<=m;i++){
        scanf("%lld",&j);
        p[0][j]=1;
    }
    for(i=1;i<=(long long)log2(k);i++)
        for(j=0;j<n;j++)
            for(l=0;l<n;l++)
                if(p[i-1][j]&&p[i-1][l])
                    p[i][(j*l)%n]=1;
    long long ch=1;
    for(i=0;i<=(long long)log2(k);i++){
        if((((long long)1<<i)&k)==0)    continue;
        if(ch){
            for(j=0;j<n;j++){
                if(p[i][j]==1){
                    ans[j]=1;
                }
            }
            ch=0;
            continue;
        }
        for(j=0;j<n;j++){
            temp[j]=ans[j];
            ans[j]=0;
        }
        for(j=0;j<n;j++)
            for(l=0;l<n;l++)
                if(p[i][j] && temp[l])
                    ans[(j*l)%n]=1;
    }
    for(i=0;i<n;i++)
        if(ans[i]==1)
            printf("%lld ",i);
    return 0;
}
