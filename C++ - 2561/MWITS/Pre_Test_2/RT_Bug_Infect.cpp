/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int bug[62][1510],ans[1510],tempp[1510];
int main(){
    long long kk;
    int m,n,temp;
    scanf("%lld %d %d",&kk,&m,&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        bug[0][temp] = 1;
        ans[temp] = 1;
    }
    for(int i=1;i<=60;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<m;k++){
                if(!bug[i-1][j] || !bug[i-1][k])    continue;
                bug[i][(j*k)%m] = 1;
            }
        }
    }
    kk--;
    for(int i=60;i>=0;i--){
        if(kk & (1ll<<i)){
            // printf("i: %lld %lld\n",i,(1<<i));
            for(int j=0;j<m;j++){
                for(int k=0;k<m;k++){
                    if(!ans[j] || !bug[i][k])   continue;
                    tempp[(j*k)%m] = 1;
                    // printf("%lld %lld %lld\n",j,k,(j*k)%m);
                }
            }
            for(int j=0;j<m;j++)
                ans[j] = tempp[j];
            memset(tempp,0,sizeof tempp);
        }
    }
    for(int i=0;i<m;i++){
        if(!ans[i]) continue;
        printf("%d ",i);
    }
	return 0;
}
