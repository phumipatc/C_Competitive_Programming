/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int RMQ[20][100010];
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=0;i<n;i++)
        scanf("%d",&RMQ[0][i]);
    for(int i=1;i<=log2(n);i++)
        for(int j=0;j+(1<<i)-1<n;j++)
            RMQ[i][j] = max(RMQ[i-1][j],RMQ[i-1][j+(1<<(i-1))]);
    int u,v,k;
    while(q--){
        scanf("%d %d",&u,&v);
        k = log2(v-u+1);
        printf("%d\n",max(RMQ[k][u],RMQ[k][v-(1<<k)+1]));
    }
	return 0;
}