/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    long long q,y,x;
    scanf("%lld",&q);
        while(q--){
        scanf("%lld %lld",&y,&x);
        if((y-x) == 1)  printf("NO\n");
        else            printf("YES\n");
    }
	return 0;
}