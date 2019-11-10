/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mark[100010],a[100010];
int main(){
    int q,n,m,gcd;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d",&n,&m,&a[1]);
        gcd = a[1];
        for(int i=2;i<=n;i++){
            scanf("%d",&a[i]);
            gcd = __gcd(gcd,a[i]);
        }
        printf("%d\n",m-gcd);
    }
	return 0;
}