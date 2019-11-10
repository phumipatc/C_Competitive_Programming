/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
pair<int,int> p[100100];
int LIS[100100],a[100100];
int main()
{
    int q,i,pos,t,n,v,idx,maxx;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&v);
        for(i=0;i<n;i++){
            scanf("%d %d",&pos,&t);
            p[i].first=pos+(v*t);
            p[i].second=((-1)*pos)+(v*t);
//            printf("%d %d\n",p[i].first,p[i].second);
        }
        sort(p,p+n);
        for(i=0;i<n;i++)
            a[i]=p[i].second;
        for(i=0,maxx=0;i<n;i++){
            idx=upper_bound(LIS,LIS+maxx,a[i])-LIS;
            if(maxx==idx)    maxx++;
            LIS[idx]=a[i];
        }
        printf("%d\n",maxx);
    }
    return 0;
}
/*
1
4 1
1 1
1 2
2 2
3 3
*/
