/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char a[1010],b[1010];
string str;
unordered_map<string ,int > mapp;
int mark[1010];
int main(){
	// ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	freopen("in5.txt","r",stdin);
	freopen("out5.txt","w",stdout);
	int q,n,m;
	scanf("%d",&q);
	for(int z=1;z<=q;z++){
		scanf("%d %s",&n,a+1);
		for(int i=1;i<=n;i++){
			scanf(" %s",b+1);
			m = strlen(b+1);
			for(int i=m;i>=1;i--){
				str.push_back(b[i]);
				mapp[str] = 1;
				// cout << str << '\n';
			}
			str.clear();
		}
		m = strlen(a+1);
		for(int i=1;i<=m;i++)
			mark[i] = 1e9;
		for(int i=1;i<=m;i++){
			for(int j=i;j>=1;j--){
				str.push_back(a[j]);
				// cout << str << '\n';
				if(!mapp[str])			continue;
				if(mark[j-1] == 1e9)	continue;
				mark[i] = min(mark[i],mark[j-1]+1);
				// printf("%d %d\n",i,j,mark[i]);
			}
			str.clear();
		}
		if(mark[m] == 1e9)	printf("Case #%d: -1\n",z);
		else				printf("Case #%d: %d\n",z,mark[m]);
		mapp.clear();
	}
	return 0;
}
/*
3
2
mississippi
missi
lippi
2
sisi
missi
lippi
2
lissi
missi
lippi
*/