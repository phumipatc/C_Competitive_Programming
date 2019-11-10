/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long n,c;
struct A{
    long long a[6][6];
    A operator * (const A&o) const{
        A temp;
        for(long long i=0;i<n;i++){
            for(long long j=0;j<n;j++){
                temp.a[i][j] = 0;
                for(long long k=0;k<n;k++){
                    temp.a[i][j]+=(a[i][k]*o.a[k][j]);
                    temp.a[i][j]%=c;
                }
            }
        }
        return temp;
    }
};
A ans,a;
void po(long long n){
    if(n == 1){
        ans = a;
        return ;
    }
    po(n/2);
    ans = ans*ans;
    if(n%2) ans = ans*a;
}
int main(){
    long long b;
    scanf("%lld",&n);
    for(long long i=0;i<n;i++)
        for(long long j=0;j<n;j++)
            scanf("%lld",&a.a[i][j]);
    scanf("%lld %lld",&b,&c);
    if(b == 0){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j)  printf("%d ",(1%c));
                else        printf("0 ");
            }
            printf("\n");
        }
        return 0;
    }
    po(b);
    for(long long i=0;i<n;i++){
        for(long long j=0;j<n;j++){
            printf("%lld ",ans.a[i][j]);
        }
        printf("\n");
    }
	return 0;
}
