/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[200010],countt[30][200010],ans[30];
char str[200010];
int main(){
	int q,n,m;
	scanf("%d",&q);
	while(q--){
		scanf("%d %d %s",&n,&m,str+1);
		for(int i=1;i<=m;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+m+1);
		for(int i=1;i<=n;i++){
			for(int j=0;j<26;j++)
				countt[j][i] = countt[j][i-1];
			countt[str[i]-'a'][i]++;
		}
		for(int i=1;i<=m;i++)
			for(int j=0;j<26;j++)
				ans[j]+=countt[j][a[i]];
		for(int i=0;i<26;i++){
			ans[i]+=countt[i][n];
			printf("%d ",ans[i]);
		}
		printf("\n");
		memset(ans,0,sizeof ans);
	}
	return 0;
}