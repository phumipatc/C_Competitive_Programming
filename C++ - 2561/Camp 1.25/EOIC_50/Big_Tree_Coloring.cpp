/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int q,n,k,ans,u,v;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&k);
        for(int i=1;i<n;i++){
            scanf("%d %d",&u,&v);
        }
        ans = 1;
        for(int i=2;i<=n;i++)
            ans = (ans*(k-1))%93563;
        ans = (ans*k)%93563;
        printf("%d\n",ans);
    }
	return 0;
}
