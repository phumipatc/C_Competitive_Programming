/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int pos[1000100];
int main()
{
    int n,m,k,l,p,idx1,idx2,shift,ans,i,j;
    scanf("%d %d %d %d",&n,&m,&k,&l);
    for(i=0;i<n;i++)
        scanf("%d",&pos[i]);
    for(i=0;i<k;i++){
        ans=shift=0;
        for(j=0;j<m;j++){
            scanf("%d",&p);
            idx1=lower_bound(pos+shift,pos+n,p-l)-pos;
            idx2=shift=upper_bound(pos+shift,pos+n,p+l)-pos;
            ans+=idx2-idx1;
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
3 2 4 100
100 300 500
200 1000
199 1000
200 600
1000 1001
*/
