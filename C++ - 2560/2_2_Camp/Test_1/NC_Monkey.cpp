/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
int mic[5010],a[5010];
using namespace std;
int main(){
    int n,k,i,j,maxx,minn;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++){
        minn=1e9;
        maxx=-1;
        for(j=1;j<=k;j++){
            if(i-j<0) continue;
            maxx=max(maxx,a[i-j+1]);
            minn=min(minn,maxx+mic[i-j]);
        }
        mic[i]=minn;
    }
    printf("%d\n",mic[n]);
    return 0;
}
/*
8 5
1 4 0 3 2 7 2 2
*/
