/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int countt[12],num[12];
int main(){
    int n,temp,ans,maxx,minn;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        countt[temp]++;
        for(int j=1;j<=10;j++){
            if(countt[j] == 0)  continue;
            maxx = 0,minn = 1e9;
            for(int k=1;k<=10;k++){
                if(k == j){
                    if(countt[k]-1 == 0)    continue;
                    maxx = max(maxx,countt[k]-1);
                    minn = min(minn,countt[k]-1);
                }else{
                    if(countt[k] == 0)      continue;
                    maxx = max(maxx,countt[k]);
                    minn = min(minn,countt[k]);
                }
            }
            if(maxx == minn || (maxx == 0 && minn == 1e9)){
                ans = i;
                break;
            }
        }
    }
    printf("%d\n",ans);
	return 0;
}
