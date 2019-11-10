/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
const int mod=1e7+19;
struct matrix{
    long long a[2][2];
    matrix operator *(const matrix &o) const{
        matrix temp;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                temp.a[i][j]=0;
                for(int k=0;k<2;k++){
                    temp.a[i][j]+=a[i][k]*o.a[k][j];
                    temp.a[i][j]%=mod;
                }
            }
        }
        return temp;
    }
};
matrix fibo={1,1,1,0},ans;
void power(long long n){
    if(n==1){
        ans=fibo;
        return ;
    }
    power(n/2);
    ans=ans*ans;
    if(n%2)  ans=ans*fibo;
    return ;
}
int main()
{
    int q;
    scanf("%d",&q);
    while(q--){
        long long n;
        scanf("%lld",&n);
        if(n==0){
            printf("0\n");
            continue;
        }
        ans=fibo;
        power(n);
        printf("%lld\n",ans.a[0][1]);
    }
    return 0;
}
