/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y,v;
};
A m[32];
int main(){
    int q,n,a,b,k,maxx;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d %d",&n,&a,&b,&k);
        for(int i=1;i<=n;i++)
            scanf("%d %d %d",&m[i].x,&m[i].y,&m[i].v);
        maxx = 0;
        printf("%d\n",maxx);
    }
	return 0;
}