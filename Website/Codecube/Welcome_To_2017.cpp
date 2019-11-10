/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mark[4010];
int main(){
    int n,temp,maxx = -1,ans = -1,minn = 1e9;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        maxx = max(maxx,temp);
        mark[temp]++;
    }
    for(int i=1;i<=maxx;i++){
        if(mark[i]!=1)  continue;
        if(abs(i-2017)<minn){
            minn = abs(i-2017);
            ans = i;
        }else if(abs(i-2017) == minn){
            ans = min(ans,i);
        }
    }
    printf("%d\n",ans);
	return 0;
}
