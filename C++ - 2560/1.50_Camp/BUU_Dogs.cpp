/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long mic[1010][1010];
int main(){
    int i,j,r,c,n;
    scanf("%d %d %d",&c,&r,&n);
    while(n--){
        scanf("%d %d",&j,&i);
        mic[i][j]=-1;
    }
    mic[1][1]=1;
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            if(mic[i][j]==-1)
                mic[i][j]=0;
            else
                mic[i][j]+=mic[i-1][j]+mic[i][j-1];
        }
    }
    printf("%lld\n",mic[r][c]);
return 0;
}
