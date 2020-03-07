/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
	int i,j,v,id;
	bool operator < (const A&o) const{
		return v>o.v;
	}
};
A now;
priority_queue<A > heap;
pair<int ,int > a[310][5010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int r,c,m,opr,x,y,v;
	cin >> r >> c >> m;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			heap.push({i,j,0,0});
	for(int i=1;i<=m;i++){
		cin >> opr;
		if(opr == 1){
			cin >> x >> y >> v;
			a[x][y] = {v,i};
			heap.push({x,y,v,i});
		}else if(opr == 2){
			cin >> x >> v;
			a[x][0] = {v,i};
			heap.push({x,0,v,i});
		}else if(opr == 3){
			cin >> x >> y;
			if(a[x][0].second>a[x][y].second)	cout << a[x][0].first << '\n';
			else								cout << a[x][y].first << '\n';
		}else{
			while(!heap.empty()){
				now = heap.top();
				if(now.j == 0){
					int ch = 0;
					if(a[now.i][0].second>now.id){
						heap.pop();
						continue;
					}
					for(int j=1;j<=c;j++){
						if(a[now.i][j].second<now.id){
							ch = 1;
							break;
						}
					}
					if(!ch){
						heap.pop();
						continue;
					}
					cout << now.v << '\n';
					break;
				}else{
					if(a[now.i][now.j].second>now.id || a[now.i][0].second>now.id){
						heap.pop();
						continue;
					}
					cout << now.v << '\n';
					break;
				}
			}
		}
	}
	return 0;
}