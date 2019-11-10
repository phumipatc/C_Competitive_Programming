/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[35];
int main(){
    long long q,n,neg;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        memset(a,0,sizeof a);
        if(n == 0){
            printf("n\n");
            continue;
        }
        neg = 0;
        if(n<0) neg = 1;
        n = abs(n);
        for(long long i=0;i<=31;i++){
            if(n & (1ll<<i))
                a[i] = 1;
        }
        for(long long i=0;i<=32;i++){
            if(a[i] == 1 && a[i+1] == 1){
                a[i] = -1;
                a[i+1] = 0;
                a[i+2]++;
            }else if(a[i] == 2){
                a[i] = 0;
                a[i+1] ++;
            }
        }
        long long ch = 0;
        for(long long i=32;i>=0;i--){
            if(a[i] == 1){
                ch = 1;
                if(!neg)    printf("p");
                else        printf("e");
            }else if(a[i] == 0){
                if(ch)      printf("n");
            }else if(a[i] == -1){
                if(!neg)    printf("e");
                else        printf("p");
            }
        }
        printf("\n");
    }
	return 0;
}
