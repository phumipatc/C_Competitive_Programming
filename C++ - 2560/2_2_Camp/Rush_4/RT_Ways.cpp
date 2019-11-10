/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 10000019
using namespace std;
struct A{
    long long a[4][4];
};
A temp;
A multi(A a,A b){
    memset(temp.a,0,sizeof temp.a);
    for(long long i=0;i<4;i++){
        for(long long j=0;j<4;j++){
            for(long long k=0;k<4;k++){
                temp.a[i][j]+=a.a[i][k]*b.a[k][j];
                temp.a[i][j]%=MOD;
            }
        }
    }
    return temp;
}
A a[50];
int main(){
    long long q;
    A ans;
    a[0]=A{{0,0,1,0,1,0,1,0,0,0,0,1,0,1,0,0}};
    for(long long i=1;i<50;i++)
        a[i]=multi(a[i-1],a[i-1]);
    scanf("%lld",&q);
    while(q--){
        ans=A{{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}};
        long long n;
        scanf("%lld",&n);
        n--;
        for(long long i=0;i<50;i++)
            if(n&(1ll<<i))
                ans=multi(ans,a[i]);
        for(long long i=0;i<4;i++)
            printf("%lld ",ans.a[i][0]);
        printf("\n");
    }
    return 0;
}
