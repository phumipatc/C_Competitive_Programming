/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int h[100100],mic[100100];
int main()
{
    int q,n,k,i,idx,j;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&k);
        for(i=1;i<=n;i++)
            scanf("%d",&h[i]);
        mic[1]=1;
        for(i=2;i<=n;i++){
            mic[i]=mic[i-1];
            int idx=lower_bound(h+1,h+n+1,h[i]-k)-h-1;
            mic[i]-=mic[idx];
            mic[i]+=mic[i-1];
            mic[i]%=95959;
        }
        printf("%d\n",(mic[n]-mic[n-1]+95959)%95959);
        memset(h,0,sizeof h);
        memset(mic,0,sizeof mic);
    }
    return 0;
}
