/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long det(long long n,long long a[10][10]){
    if(n == 1)  return a[0][0];
    long long ans = 0,co[10][10],type = 1;
    for(long long i=0;i<n;i++){
        long long p = 0,q = 0;
        for(long long k=0;k<n;k++){
            for(long long l=0;l<n;l++){
                if(k!=0 && l!=i){
                    co[p][q++] = a[k][l];
                    if(q == n-1)
                        p++,q = 0;
                }
            }
        }
        ans+=(type*a[0][i]*det(n-1,co));
        type = -type;
    }
    return ans;
}
int main(){
    long long n,a[10][10];
    scanf("%lld",&n);
    for(long long i=0;i<n;i++)
        for(long long j=0;j<n;j++)
            scanf("%lld",&a[i][j]);
    printf("%lld\n",det(n,a));
    return 0;
}
