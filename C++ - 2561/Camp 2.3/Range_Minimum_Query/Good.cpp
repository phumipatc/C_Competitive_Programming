/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int RMQ[22][1000010];
int main(){
	int n,q,temp,u,v;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++)
		scanf("%d",&RMQ[0][i]);
	temp = log2(n);
	for(int i=1;i<=temp;i++){
		for(int j=0;j+(1<<i)-1<n;j++){
			RMQ[i][j] = max(RMQ[i-1][j],RMQ[i-1][j+(1<<(i-1))]);
		}
	}
	while(q--){
		scanf("%d %d",&u,&v);
		temp = log2(v-u+1);
		printf("%d\n",max(RMQ[temp][u],RMQ[temp][v-(1<<temp)+1]));
	}
	return 0;
}
