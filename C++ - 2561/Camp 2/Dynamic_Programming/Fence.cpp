/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int d[510][510],r[510][510];
int main(){
    int n,m,k,q = 2,ans,rr,cc;
    while(q--){
        ans = 0;
        scanf("%d %d %d",&n,&m,&k);
        while(k--){
            scanf("%d %d",&rr,&cc);
            rr++,cc++;
            r[rr][cc+1]++;
            d[rr+1][cc]++;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                r[i][j]+=r[i][j-1];
                d[i][j]+=d[i-1][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                for(int k=1;k<=min(i,j);k++){
                    if(r[i][j]+1 == r[i][j+1] || d[i][j]+1 == d[i+1][j])    continue;
                    if(r[i][j] == r[i][j-k+1] && d[i][j] == d[i-k+1][j] && r[i-k+1][j] == r[i-k+1][j-k+1] && d[i][j-k+1] == d[i-k+1][j-k+1]){
                        ans = max(ans,k);
                    }
                }
            }
        }
        printf("%d\n",ans);
        memset(r,0,sizeof r);
        memset(d,0,sizeof d);
    }
	return 0;
}
