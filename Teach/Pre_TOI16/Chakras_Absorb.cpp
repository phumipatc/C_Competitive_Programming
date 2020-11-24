/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Dijkstra
	Status	: Finished
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
typedef pair<long long ,long long > PLL;
struct A{
	int i,j,v;
	bool operator < (const A&o) const{
		return v>o.v;
	}
};
priority_queue<A > heap;
int a[1010][1010],minn[1010][1010];
int dir[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n;
	PII st = {0,0},en;
	cin >> n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
			minn[i][j] = 1e9;
			if(a[i][j] == 0){
				if(st == make_pair(0,0))	st = {i,j};
				else						en = {i,j};
			}
		}
	}
	heap.push({st.first,st.second,0});
	while(!heap.empty()){
		auto now = heap.top();
		heap.pop();
		if(make_pair(now.i,now.j) == en){
			cout << now.v << '\n';
			break;
		}
		for(int k=0;k<4;k++){
			int ni = now.i+dir[0][k];
			int nj = now.j+dir[1][k];
			if(ni<1 || nj<1 || ni>n || nj>n)		continue;
			if(minn[ni][nj]<=max(now.v,a[ni][nj]))	continue;
			minn[ni][nj] = max(now.v,a[ni][nj]);
			heap.push({ni,nj,minn[ni][nj]});
		}
	}
	return 0;
}