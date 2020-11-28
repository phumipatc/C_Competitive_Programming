/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: queue
	Status	: finished
*/
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
LL minN(vector<LL > a){
	LL minn = 1e18;
	for(auto x:a)
		minn = min(minn,x);
	return minn;
}
LL maxN(vector<LL > a){
	LL maxx = -1e18;
	for(auto x:a)
		maxx = max(maxx,x);
	return maxx;
}
queue<int > que[12];
unordered_map<int ,int > mapp;
bool mark[12];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m,u,v;
	char opr;
	cin >> n >> m;
	while(m--){
		cin >> u >> v;
		mapp[v] = u;
	}
	while(1){
		cin >> opr;
		if(opr == 'X')	break;
		if(opr == 'D'){
			if(que[0].empty())	cout << "empty\n";
			else{
				cout << que[que[0].front()].front() << '\n';
				que[que[0].front()].pop();
				if(que[que[0].front()].empty()){
					mark[que[0].front()] = 0;
					que[0].pop();
				}
			}
		}else if(opr == 'E'){
			cin >> v;
			if(mark[mapp[v]])	que[mapp[v]].push(v);
			else{
				mark[mapp[v]] = 1;
				que[0].push(mapp[v]);
				que[mapp[v]].push(v);
			}
		}
	}
	cout << "0\n";
	return 0;
}