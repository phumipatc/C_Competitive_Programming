/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mark[100100],warp[100100];
int main(){
    int n,i,next,ans;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&warp[i]);
    }
    for(i=1;i<=n;i++){
        ans=1;
        memset(mark,0,sizeof mark);
        mark[i]=1;
        next=i;
        while(1){
            if(mark[warp[next]])   break;
            mark[warp[next]]=1;
            next=warp[next];
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
