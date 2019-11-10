#include<bits/stdc++.h>
using namespace std;
#define N 105
#define mod 2009
int mic[N][N];
int main()
{
    int q,n,m;
    for(int i=1;i<=100;i++){
        for(int j=0;j<i;j++){
            if(j==0){
                mic[i][j]=1;
                continue;
            }
            int sum=0;
            for(int k=1;k<=i;k++){
                if(k==1){
                    sum+=mic[i-1][j];
                    sum%=mod;
                }else if(k==i){
                    sum+=mic[i-1][j-1];
                    sum%=mod;
                }else{
                    for(int l=0;l<j;l++){
                        sum+=mic[k-1][l]*mic[i-k][j-l-1];
                        sum%=mod;
                    }
                }
            }
            mic[i][j]=sum;
        }
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        printf("%d\n",mic[n][m]);
    }
    return 0;
}
