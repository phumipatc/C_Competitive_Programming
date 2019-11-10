/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[6][20],c[20];
int dp[16][16];
int main(){
    int q,n,i,j,now,idx,ch,len;
    scanf("%d",&q);
    while(q--){
        int minn=1e9,ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf(" %s",str[i]+1);
            len=strlen(str[i]+1);
            if(minn>len){
                minn=len;
                now=i;
            }
        }
       // cout << minn << endl;
        for(int i=1;i<(1<<minn);i++){
            idx=1,ch=0;
            for(int j=1;j<=minn;j++){
                if(i&(1<<(j-1))){
                    c[idx++]=str[now][j];
                   // printf("%c",c[idx-1]);
                }
            }
           // printf("\n");
            idx--;
           // printf("%d = ",idx);
            for(int j=1;j<=n;j++){
                if(j==now)  continue;
                if(ch==1)   break;
                len=strlen(str[j]+1);
                for(int k=1;k<=idx;k++){
                    for(int l=1;l<=len;l++){
                        if(str[j][l]==c[k])  dp[k][l]=dp[k-1][l-1]+1;
                        dp[k][l]=max(dp[k][l],max(dp[k-1][l],dp[k][l-1]));
                    }
                }
                if(dp[idx][len]!=idx)   ch=1;
                memset(dp,0,sizeof dp);
            }
            if(!ch){
                ans=max(ans,idx);
            }
        }
        (ans == 0) ? printf("We always be divine\n"):printf("%d\n",ans);
    }
    return 0;
}
/*
2
5
Peatsika
Teyeol
Ponghyeon
Tiffebon
Kritteyoung
4
Teyeol
Ponghyeon
Tiffebon
Kritteyoung
*/
