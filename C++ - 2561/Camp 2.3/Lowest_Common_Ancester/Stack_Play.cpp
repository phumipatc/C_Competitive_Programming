/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[300010][20],last[300010],lv[300010];
int main(){
    int n,num,u,v;
    char opr;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %c",&opr);
        if(opr == 'a'){
            scanf("%d",&num);
            last[i] = i;
            dp[i][0] = last[num];
            lv[i] = lv[last[num]]+1;
            for(int j=1;j<=19;j++)
                dp[i][j] = dp[dp[i][j-1]][j-1];
        }else if(opr == 'b'){
            scanf("%d",&num);
            last[i] = dp[last[num]][0];
            printf("%d\n",last[num]);
        }else if(opr == 'c'){
            scanf("%d %d",&u,&v);
            last[i] = last[u];
            u = last[u],v = last[v];
            if(lv[u]>lv[v]){
                for(int j=19;j>=0;j--){
                    if(lv[dp[u][j]]<lv[v])  continue;
                    u = dp[u][j];
                }
            }
            if(lv[v]>lv[u]){
                for(int j=19;j>=0;j--){
                    if(lv[dp[v][j]]<lv[u])  continue;
                    v = dp[v][j];
                }
            }
            if(u!=v){
                for(int j=19;j>=0;j--){
                    if(dp[u][j] == dp[v][j])    continue;
                    u = dp[u][j];
                    v = dp[v][j];
                }
                printf("%d\n",lv[u]-1);
            }else   printf("%d\n",lv[u]);
        }
    }
	return 0;
}
/*
10
a 0
a 1
a 2
a 3
a 2
c 4 5
a 5
b 7
b 7
c 9 7
*/