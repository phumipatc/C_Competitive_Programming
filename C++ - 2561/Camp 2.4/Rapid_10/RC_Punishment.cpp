/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int q,n,gcd,num,maxx;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&num);
        maxx = gcd = num;
        for(int i=2;i<=n;i++){
            scanf("%d",&num);
            maxx = max(maxx,num);
            gcd = __gcd(gcd,num);
        }
        if(((maxx/gcd)-n)%2)    printf("Alive\n");
        else                    printf("Dead\n");
    }
	return 0;
}