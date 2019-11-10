/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1200],LISA[1200],LISB[1200],countt[1200];
int main()
{
    int q,n,i,maxx,index,t,m;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        m=0,maxx=-1;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++){
            index=upper_bound(LISA,LISA+m,a[i])-LISA;
            if(index>=1 && LISA[index-1]==a[i]){
                countt[i]=m;
                continue;
            }
            if(m==index){
                m++;
            }
            LISA[index]=a[i];
            countt[i]=m;
        }
        m=0;
        for(i=n-1;i>=0;i--){
            index=upper_bound(LISB,LISB+m,a[i])-LISB;
            if(index>=1 && LISB[index-1]==a[i]){
                maxx=max(maxx,countt[i]+m);
                continue;
            }
            if(m==index){
                m++;
            }
            LISB[index]=a[i];
            maxx=max(maxx,countt[i]+m);
        }
        printf("%d\n",maxx-1);
    }
    return 0;
}
/*
1
18
0 2 8 4 3 2 4 1 8 5 7 1 3 9 6 4 2 0
*/
