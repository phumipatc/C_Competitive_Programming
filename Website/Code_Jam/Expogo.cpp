/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[50],b[50];
void solve(int x,int y){
	memset(a,0,sizeof a);
	memset(b,0,sizeof b);
	int maxx;
	for(int i=0;i<32;i++){
		a[i] = ((1<<i)&abs(x))?1:0;
		b[i] = ((1<<i)&abs(y))?1:0;
		if(a[i])	maxx = i;
		if(b[i])	maxx = i;
		// printf("%d",a[i]);
	}
	// printf("\n");
	// for(int i=0;i<=maxx;i++)
	// 	printf("%d",a[i]);
	// printf("\n");
	// for(int i=0;i<=maxx;i++)
	// 	printf("%d",b[i]);
	// printf("\n");
	
	for(int i=0;i<=maxx;i++){
		if(a[i] == 2)	a[i] = 0,a[i+1]++;
		if(b[i] == 2)	b[i] = 0,b[i+1]++;
		if(a[i] == b[i] && a[i] == 0){
			if(i == 0){
				cout << "IMPOSSIBLE\n";
				return ;
			}
			if(a[i-1]){
				a[i-1] = -1;
				a[i] = 1;
			}else if(b[i-1]){
				b[i-1] = -1;
				b[i] = 1;
			}else{
				cout << "IMPOSSIBLE\n";
				return ;
			}
		}else if(a[i] == b[i] && a[i] == 1){
			if(a[i-1]){
				a[i-1] = -1;
				a[i] = 0;
				a[i+1]++;
				if(i == maxx)	maxx++;
			}else if(b[i-1]){
				b[i-1] = -1;
				b[i] = 0;
				b[i+1]++;
				if(i == maxx)	maxx++;
			}else{
				cout << "IMPOSSIBLE\n";
				return ;
			}
		}
	}
	for(int i=0;i<=maxx;i++){
		if(x<0){
			if(a[i] == 1)		a[i] = -1;
			else if(a[i] == -1)	a[i] = 1;
		}
		if(y<0){
			if(b[i] == 1)		b[i] = -1;
			else if(b[i] == -1)	b[i] = 1;
		}
	}
	string ans;
	for(int i=0;i<=maxx;i++){
		if(a[i] == b[i]){
			cout << "IMPOSSIBLE\n";
			return ;
		}
		if(a[i]){
			if(a[i] == 1)	ans.push_back('E');
			else			ans.push_back('W');
		}else{
			if(b[i] == 1)	ans.push_back('N');
			else			ans.push_back('S');
		}
	}
	ans.push_back('\n');
	cout << ans;
}
int main(){
	// freopen("0.txt","w",stdout);
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q,x,y;
	cin >> q;
	for(int t=1;t<=q;t++){
		cin >> x >> y;
		// cout << x << ' ' << y << '\n';
		cout << "Case #" << t << ": ";
		solve(x,y);
	}
	return 0;
}