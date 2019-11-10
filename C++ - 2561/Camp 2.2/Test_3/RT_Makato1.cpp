/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    int n,q,u,v;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]^=a[i-1];
    }
    while(q--){
        scanf("%d %d",&u,&v);
        printf("%d\n",a[v]^a[u-1]);
    }
	return 0;
}
