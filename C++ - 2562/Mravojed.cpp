/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
	int i,j,w;
	bool operator < (const A&o) const{
		if(i!=o.i)		return i<o.i;
		else if(j!=o.j)	return j<o.j;
		else			return w<o.w;
	}
	bool operator == (const A&o) const{
		if(i!=o.i)		return false;
		else if(j!=o.j)	return false;
		else if(w!=o.w)	return false;
		else			return true;
	}
};
vector<A > ans;
char a[110][110];
int main(){
	int r,c,minn;
	scanf("%d %d",&r,&c);
	for(int i=1;i<=r;i++)
		scanf(" %s",a[i]+1);
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			if(a[i][j] == '.')		continue;
			if(a[i-1][j] == 'x')	continue;
			if(a[i-1][j-1] == 'x')	continue;
			if(a[i][j-1] == 'x')	continue;
			minn = 1e9;
			for(int k=i+1;k<=r+1;k++){
				if(a[k][j] != 'x'){
					minn = k-i;
					break;
				}
			}
			for(int k=j+1;k<=c+1;k++){
				if(a[i][k] != 'x'){
					minn = min(minn,k-j);
					break;
				}
			}
			ans.push_back({i,j,minn});
		}
	}
	for(int i=r;i>=1;i--){
		for(int j=c;j>=1;j--){
			if(a[i][j] == '.')		continue;
			if(a[i+1][j] == 'x')	continue;
			if(a[i+1][j+1] == 'x')	continue;
			if(a[i][j+1] == 'x')	continue;
			minn = 1e9;
			for(int k=i-1;k>=0;k--){
				if(a[k][j] != 'x'){
					minn = i-k;
					break;
				}
			}
			for(int k=j-1;k>=0;k--){
				if(a[i][k] != 'x'){
					minn = min(minn,j-k);
					break;
				}
			}
			ans.push_back({i-minn+1,j-minn+1,minn});
		}
	}
	sort(ans.begin(),ans.end());
	int countt = 0;
	for(int i=0;i<ans.size();i++){
		if(i+1!=ans.size() && ans[i] == ans[i+1])	continue;
		countt++;
	}
	if(countt == 1)	ans.push_back({ans[0].i,ans[0].j,1});
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++){
		if(i+1!=ans.size() && ans[i] == ans[i+1])	continue;
		auto x = ans[i];
		cout << x.i << ' ' << x.j << ' ' << x.w << '\n';
	}
	return 0;
}
/*
3 3
xx.
xxx
.xx

10 10
.xxxxxxxx.
.xxxxxxxx.
.xxxxxxxx.
.xxxxxxxx.
.xxxxxxxx.
.xxxxxxxx.
.xxxxxxxx.
.xxxxxxxx.
....xxxx..
....xxxx..
*/