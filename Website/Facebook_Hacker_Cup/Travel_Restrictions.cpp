/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char in[55],out[55];
int mark[55][55];
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int q,n;
	scanf("%d",&q);
	for(int x=1;x<=q;x++){
		scanf("%d",&n);
		scanf(" %s %s",in+1,out+1);
		memset(mark,0,sizeof mark);
		for(int i=1;i<=n;i++)	mark[i][i] = 1;
		for(int i=1;i<n;i++){
			if(out[i] == in[i+1] && out[i] == 'Y')
				mark[i][i+1] = 1;
			if(in[i] == out[i+1] && in[i] == 'Y')
				mark[i+1][i] = 1;
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					mark[i][j]|=(mark[i][k]&mark[k][j]);
		printf("Case #%d:\n",x);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)
				printf((mark[i][j])?"Y":"N");
			printf("\n");
		}
	}
	return 0;
}