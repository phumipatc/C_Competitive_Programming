/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 9973
using namespace std;
int mem[1100];
int catalan(int n){
    if(mem[n]!=-1)  return mem[n];
    int i,a,b,sum=0;
    for(i=0;i<n;i++){
        a=catalan(i)%MOD;
        b=catalan(n-i-1)%MOD;
        sum+=a*b;
        sum%=MOD;
    }
    return mem[n]=sum;
}
int main(){
    int q;
    memset(mem,-1,sizeof mem);
    mem[0]=mem[1]=1;
    q=catalan(1000);
    scanf("%d",&q);
    while(q--){
        int n;
        scanf("%d",&n);
        printf("%d",mem[n-1]%MOD);
    }
    return 0;
}
