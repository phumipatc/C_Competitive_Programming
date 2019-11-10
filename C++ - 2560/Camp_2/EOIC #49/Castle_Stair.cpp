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
        for(i=1;i<=n;i++){
            for(j=i+1;h[i]+k>=h[j] && j<=n;j++)
                mic[j]+=mic[i];
        }
        printf("%d\n",mic[n]%95959);
        memset(h,0,sizeof h);
        memset(mic,0,sizeof mic);
    }
    return 0;
}
