/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],mic[100100],mic2[100100],ans[100100];
int main()
{
    int q,n,i,st,maxx;
    scanf("%d",&q);
    while(q--){
        maxx=-1;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            mic[i]=mic2[i]=1;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=n;i++){
            if(a[i]-a[i-1]>=1 && a[i]-a[i-1]<=2)    mic[i]+=mic[i-1];
        }
        //for(i=1;i<=n;i++)
            //printf("%d ",mic[i]);
        //printf("\n");
        for(i=n;i>0;i--){
            if(a[i-1]-a[i]>=1 && a[i-1]-a[i]<=2)    mic2[i-1]+=mic[i];
        }
        //for(i=1;i<=n;i++)
            //printf("%d ",mic2[i]);
        //printf("\n");
        for(i=1;i<=n;i++){
            if(abs(a[i-1]-a[i+1])<=4 && abs(a[i-1]-a[i+1])>=2)  ans[i]=mic[i-1]+mic2[i+1]+1;
        }
        for(i=1;i<=n;i++){
            if(ans[i]>maxx){
                maxx=ans[i];
                st=i;
            }
        }
        //for(i=1;i<=n;i++)
            //printf("%d ",ans[i]);
        //printf("\n");
        if(maxx==0)
            printf("%d 0\n",mic2[1]+1);
        else
            printf("%d %d\n",maxx,st-1);
        memset(mic,0,sizeof mic);
        memset(mic2,0,sizeof mic2);
        memset(ans,0,sizeof ans);
    }
    return 0;
}
/*
2
12
20 10 11 11 15 10 17 16 10 12 20 20
*/
