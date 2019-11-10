/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1100][1100],b[1100][1100],nona[1100],tunga[1100],nonb[1100],tungb[1100];
int main()
{
    int r,c,i,j,maxx=-1,ans;
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            scanf("%d",&a[i][j]);
            nona[i]+=a[i][j];
        }
    }
    for(j=1;j<=c;j++){
        for(i=1;i<=r;i++){
            tunga[j]+=a[i][j];
        }
    }
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            scanf("%d",&b[i][j]);
            nonb[i]+=b[i][j];
        }
    }
    for(j=1;j<=c;j++){
        for(i=1;i<=r;i++){
            tungb[j]+=b[i][j];
        }
    }
    for(i=1;i<=r;i++){
        ans=0;
        for(j=1;j<=r;j++){
            ans+=nona[j];
        }
        ans-=nona[i];
        ans+=nonb[i-1];
        ans+=nonb[i+1];
        maxx=max(maxx,ans);
        //printf("%d %d\n",ans,maxx);
    }
    for(i=1;i<=c;i++){
        ans=0;
        for(j=1;j<=c;j++){
            ans+=tunga[j];
        }
        ans-=tunga[i];
        ans+=tungb[i-1];
        ans+=tungb[i+1];
        maxx=max(maxx,ans);
        //printf("%d %d\n",ans,maxx);
    }
    printf("%d\n",maxx);
    return 0;
}
/*
5 4
2 3 2 1
4 5 8 4
2 5 3 2
1 4 0 2
2 1 8 1
1 2 3 2
2 2 2 1
2 1 1 2
1 2 1 0
1 1 1 0
*/
