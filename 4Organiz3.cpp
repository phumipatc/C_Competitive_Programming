#include<bits/stdc++.h>
using namespace std;
struct A{
    long long a[202][202];
};
A tmp;
A ans;
A m[32];
long long n;
#define Mod 1000000007
void mul(A *a,A *b){
    memset(tmp.a,0,sizeof tmp.a);
    long long i,j,k;
    for(i=0;i<202;i++){
        for(j=0;j<202;j++){
            for(k=0;k<202;k++){
                tmp.a[i][j]+=(a->a[i][k])*(b->a[k][j]);
                tmp.a[i][j]%=Mod;
            }
        }
    }
}
int main(){
    long long k,i,j;
    m[0].a[0][0]=1;
    for(i=1;i<=200;i++){
        for(j=0;j<=i;j++){
            m[0].a[i][j]=m[0].a[i-1][j];
            m[0].a[i][j]%=Mod;
            if(j!=0){
                m[0].a[i][j]+=m[0].a[i-1][j-1];
                m[0].a[i][j]%=Mod;
            }
        }
    }
    scanf("%lld %lld",&n,&k);
    m[0].a[201][201]=m[0].a[201][k]=1;
    for(i=1;i<30;i++){
        mul(&m[i-1],&m[i-1]);
        m[i]=tmp;
    }
    for(i=0;i<=200;i++){
        ans.a[i][0]=1;
    }
    for(i=0;i<30;i++){
        if((1ll<<i)&n){
            mul(&m[i],&ans);
            ans=tmp;
        }
    }
    printf("%lld",ans.a[201][0]);
return 0;
}
