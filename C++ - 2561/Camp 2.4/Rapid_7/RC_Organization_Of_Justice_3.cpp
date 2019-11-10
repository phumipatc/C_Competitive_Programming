/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
struct A{
    long long a[202][202];
};
A temp,ans,p[32];
long long n;
void multiply(A *a,A *b){
    memset(temp.a,0,sizeof temp.a);
    long long i,j,k;
    for(i=0;i<202;i++){
        for(j=0;j<202;j++){
            for(k=0;k<202;k++){
                temp.a[i][j]+=(a->a[i][k])*(b->a[k][j]);
                temp.a[i][j]%=MOD;
            }
        }
    }
}
int main(){
    long long k,i,j;
    p[0].a[0][0] = 1;
    for(i=1;i<=200;i++){
        for(j=0;j<=i;j++){
            p[0].a[i][j] = p[0].a[i-1][j];
            p[0].a[i][j]%=MOD;
            if(j!=0){
                p[0].a[i][j]+=p[0].a[i-1][j-1];
                p[0].a[i][j]%=MOD;
            }
        }
    }
    scanf("%lld %lld",&n,&k);
    p[0].a[201][201] = p[0].a[201][k] = 1;
    for(i=1;i<30;i++){
        multiply(&p[i-1],&p[i-1]);
        p[i] = temp;
    }
    for(i=0;i<=200;i++)
        ans.a[i][0] = 1;
    for(i=0;i<30;i++){
        if((1ll<<i) & n){
            multiply(&p[i],&ans);
            ans = temp;
        }
    }
    printf("%lld",ans.a[201][0]);
return 0;
}
