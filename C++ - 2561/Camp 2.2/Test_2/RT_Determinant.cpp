/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long det(long long n,long long a[][10]){
    // printf("%lld\n",n);
    // for(long long i=0;i<n;i++){
    //     for(long long j=0;j<n;j++){
    //         printf("%lld ",a[i][j]);
    //     }
    //     printf("\n");
    // }
    if(n == 1)  return a[0][0];
    if(n == 2)  return (a[0][0]*a[1][1])-(a[0][1]*a[1][0]);
    long long b[10][10],countt,sum = 0;
    for(long long j=0;j<n;j++){
        countt = 0;
        for(long long k=1;k<n;k++){
            for(long long l=0;l<n;l++){
                if(l == j)  continue;
                // printf("idx : %lld %lld %lld %lld %lld\n",k,l,a[k][l],countt/(n-1),countt%(n-1));
                b[countt/(n-1)][countt%(n-1)] = a[k][l];
                countt++;
            }
        }
        if(j%2 == 0)    sum+=det(n-1,b)*a[0][j];
        else            sum-=det(n-1,b)*a[0][j];
    }
    return sum;
}
int main(){
    long long n;
    long long a[10][10];
    scanf("%lld",&n);
    for(long long i=0;i<n;i++)
        for(long long j=0;j<n;j++)
            scanf("%lld",&a[i][j]);
    printf("%lld\n",det(n,a));
	return 0;
}
/*
8
25 46 10 28 16 5 2 9
42 59 75 13 24 86 2 4
3 5 12 18 76 72 29 10
13 14 19 16 15 18 31 58
47 10 53 62 48 49 51 5
9 20 13 42 75 48 61 53
82 41 26 55 64 51 21 12
34 57 48 46 10 42 85 76
*/