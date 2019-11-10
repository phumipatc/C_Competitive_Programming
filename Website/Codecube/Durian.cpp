/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000010],b[1000010];
int main(){
    int n,x,y,maxx=0,minn=1<<30,ans=0,i,j;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&x,&y);
        a[x]++;
        b[y]++;
        maxx=max(maxx,y);
        minn=min(minn,x);
    }
    for(i=minn;i<=maxx;i++){
        a[i]+=a[i-1];
        b[i]+=b[i-1];
    }
    for(i=minn;i<=maxx;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    for(i=minn;i<=maxx;i++){
        printf("%d ",b[i]);
    }
    for(i=maxx;i>minn;i--){
        for(j=minn;j<maxx;j++){
                ans=max(ans,b[i]-a[j]);
        }
    }
    printf("%d\n",ans);
return 0;
}
