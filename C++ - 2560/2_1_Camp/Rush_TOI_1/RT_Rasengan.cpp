/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int h[300100],high[300100],low[300100];
int main()
{
    int n,m,i,height,k,l;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&h[i]);
    for(i=1,k=0,l=0;i<=n;i++){
        if(h[i]>h[i-1] && h[i]>h[i+1])  high[k++]=h[i];
        if(h[i]<h[i-1] && h[i]<h[i+1])  low[l++]=h[i];
    }
    sort(high,high+k);
    sort(low,low+l);
    while(m--){
        scanf("%d",&height);
        int idx = lower_bound(high,high+k,height)-high;
        int idx2 = lower_bound(low,low+l,height)-low;
        int ans=(k-idx)-(l-idx2);
        printf("%d\n",ans);
    }
    return 0;
}
/*
7 3
200
250
100
200
50
300
100
215
70
110
*/
