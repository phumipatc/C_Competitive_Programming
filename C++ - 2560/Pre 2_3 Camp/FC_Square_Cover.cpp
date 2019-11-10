/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,x,y,minx,miny,maxx,maxy;
    minx=miny=1e9;
    maxx=maxy=-1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&x,&y);
        minx=min(minx,x);
        miny=min(miny,y);
        maxx=max(maxx,x);
        maxy=max(maxy,y);
//        printf("%d %d\n%d %d\n",minx,miny,maxx,maxy);
    }
    int ans=max((maxx-minx),(maxy-miny));
    printf("%d\n",ans*ans);
    return 0;
}
