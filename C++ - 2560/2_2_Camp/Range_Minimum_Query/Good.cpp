/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int ans[20][100100];
int main(){
    int n,q,st,en;
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;i++)
        scanf("%d",&ans[0][i]);
    for(int i=1;i<=log2(n);i++)
        for(int j=0;j+(1<<i)-1<n;j++)
            ans[i][j]=max(ans[i-1][j],ans[i-1][j+(1<<(i-1))]);
    while(q--){
        scanf("%d %d",&st,&en);
        int k=(int)log2(en-st+1);
        printf("%d\n",max(ans[k][st],ans[k][en-(1<<k)+1]));
    }
    return 0;
}
