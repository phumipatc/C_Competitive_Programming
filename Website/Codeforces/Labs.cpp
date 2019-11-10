/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int ans[310][310];
int main(){
    int n,temp;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            temp = n*(i-1)+j;
            if(i%2 == 1)    ans[n-j+1][i] = temp;
            else            ans[j][i] = temp;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%d ",ans[i][j]);
        printf("\n");
    }
    return 0;
}