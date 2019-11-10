/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int RMQ[20][100010];
int main(){
    int k,n,q,a,b;
    cin >> n >> q;
    for(int i=0;i<n;i++)
        cin >> RMQ[0][i];
    for(int i=1;i<=log2(n);i++)
        for(int j=0;j+(1<<i)-1<n;j++)
            RMQ[i][j] = max(RMQ[i-1][j],RMQ[i-1][j+(1<<(i-1))]);
    while(q--){
        scanf("%d %d",&a,&b);
        k = log2(b-a+1);
        printf("%d\n",max(RMQ[k][a],RMQ[k][b-(1<<k)+1]));
    }
    return 0;
}
