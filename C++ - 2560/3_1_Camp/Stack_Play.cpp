/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int dp[22][300010],lv[300010],st[300010];
int main(){
    int n,a,b;
    char opr;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %c",&opr);
        if(opr == 'a'){
            scanf("%d",&a);
            dp[0][i] = st[a];
            for(int j=1;j<=20;j++)  dp[j][i] = dp[j-1][dp[j-1][i]];
            st[i] = i;
            lv[i] = lv[st[a]]+1;
        }else if(opr == 'b'){
            scanf("%d",&a);
            if(st[a] == 0)  printf("-1\n");
            else            printf("%d\n",st[a]);
            st[i] = dp[0][st[a]];
            lv[i] = lv[dp[0][st[a]]];
        }else{
            scanf("%d %d",&a,&b);
            st[i] = a = st[a],b = st[b];
            if(lv[a]<lv[b]) swap(a,b);
            for(int j=20;j>=0;j--){
                if(lv[dp[j][a]]<lv[b])  continue;
                a = dp[j][a];
            }
            if(a == b){
                printf("%d\n",lv[a]);
                continue;
            }
            for(int j=20;j>=0;j--)
                if(dp[j][a]!=dp[j][b])
                    a = dp[j][a],b = dp[j][b];
            printf("%d\n",lv[dp[0][a]]);
        }
    }
    return 0;
}
