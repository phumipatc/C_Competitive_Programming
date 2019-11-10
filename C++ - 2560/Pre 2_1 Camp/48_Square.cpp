#include<bits/stdc++.h>
using namespace std;
int mic[400][400];
int main(){
    int i,j,k,q,n,m;
    for(i=1;i<=350;i++)
        for(j=1;j<=350;j++)
            mic[i][j]=1e9;
    for(i=1;i<=350;i++)
        for(j=1;j<=350;j++)
            if(i==j)        mic[i][j]=1;
            else if(i==1)   mic[i][j]=mic[i][j-1]+1;
            else if(j==1)   mic[i][j]=mic[i-1][j]+1;
    for(i=2;i<=350;i++){
        for(j=2;j<=350;j++){
            for(k=1;k<i;k++){
//              printf("i: %d\n",mic[i][k]+mic[i][j-k]);
                mic[i][j]=min(mic[i][j],mic[k][j]+mic[i-k][j]);
            }
            for(k=1;k<j;k++){
//              printf("j :%d\n",mic[k][j]+mic[i-k][j]);
                mic[i][j]=min(mic[i][j],mic[i][k]+mic[i][j-k]);
            }
        }
    }
//    for(i=1;i<=10;i++){
//        for(j=1;j<=10;j++){
//            printf("%d ",mic[i][j]);
//        }
//        printf("\n");
//    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        printf("%d\n",mic[n][m]);
    }
    return 0;
}
