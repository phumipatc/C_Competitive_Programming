/*
    TASK:
    LANG: CPP
    AUTHOR: Phumipat C.
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010],a[1010],b[1010],c[1010];
int main(){
    int q,n,m,temp,countt;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        dp[1][1] = 1;
        countt = 0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            countt+=a[i];
        }
        temp = 0;
        for(int i=1;i<=n;i++){
            for(int j=temp+1;j<=temp+a[i];j++){
                b[j] = i;
            }
            temp+=a[i];
        }
        for(int i=1;i<=m;i++){
            scanf("%d",&temp);
            c[temp] = b[temp];
        }
        c[1] = 1,c[countt] = n;
        for(int i=1;i<=countt;i++){
            if(c[i] == 0){
                for(int j=1;j<=n;j++){
                    dp[i][j]+=dp[i-1][j]+dp[i-1][j-1];
                    dp[i][j]%=9901;
                }
            }else{
                dp[i][c[i]]+=dp[i-1][c[i]]+dp[i-1][c[i]-1];
                dp[i][c[i]]%=9901;
            }
        }
        printf("%d\n",dp[countt][n]);
        memset(dp,0,sizeof dp);
        memset(c,0,sizeof c);
    }
    return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005],a[1005],b[1005],c[1005];
int main()
{
    int q,i,j,old,n,m,cnt=0;
    scanf("%d",&q);
    while(q--){
        cnt=0;
        scanf("%d %d",&n,&m);
        dp[1][1]=1;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            cnt+=a[i];
        }
        old=0;
        for(i=1;i<=n;i++){
            for(j=old+1;j<=old+a[i];j++){
                b[j]=i;
            }
            old=j-1;
        }
        for(i=1;i<=m;i++){
            scanf("%d",&j);
            c[j]=b[j];
        }
        c[1]=1;c[cnt]=n;
        for(i=1;i<=cnt;i++){
            if(c[i]==0){
                for(j=1;j<=n;j++){
                    dp[i][j]+=dp[i-1][j]+dp[i-1][j-1];
                    dp[i][j]%=9901;
                }
            }
            else{
                dp[i][c[i]]+=dp[i-1][c[i]]+dp[i-1][c[i]-1];
                dp[i][c[i]]%=9901;
            }
        }
        printf("%d\n",dp[cnt][n]);
        memset(dp,0,sizeof dp);
        memset(c,0,sizeof c);
    }
    return 0;
}
*/
