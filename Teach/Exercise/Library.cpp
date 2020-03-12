/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define opr first
using namespace std;
typedef long long LL;
map<int,int > mapp;
set<int > sett;
set<int >::iterator it;
pair<char ,int > p[100010];
int tree[200010],a[100010];
void update(int idx,int v){
	while(idx<=200003){
		tree[idx]+=v;
		idx+= idx & -idx;
	}
}
int query(int idx){
	int sum = 0;
	while(idx>0){
		sum+=tree[idx];
		idx-= idx & -idx;
	}
	return sum;
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,num;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		sett.insert(a[i]);
	}
	int m;
	cin >> m;
	for(int i=1;i<=m;i++){
		cin >> p[i].first;
		if(p[i].opr == 'L')	continue;
		cin >> p[i].second;
		sett.insert(p[i].second);
	}
	int countt = 1;
	for(auto x:sett)
		mapp[x] = countt++;
	sett.clear();
	for(int i=1;i<=n;i++){
		sett.insert(a[i]);
		update(mapp[a[i]],1);
	}
	for(int i=1;i<=m;i++){
		if(p[i].opr == 'A'){
			it = sett.lower_bound(p[i].second);
			if(it!=sett.end() && *it == p[i].second)	cout << "Yes\n";
			else										cout << "No\n";
		}else if(p[i].opr == 'B'){
			sett.erase(p[i].second);
			update(mapp[p[i].second],-1);
		}else if(p[i].opr == 'R'){
			sett.insert(p[i].second);
			update(mapp[p[i].second],1);
		}else if(p[i].opr == 'F'){
			cout << query(mapp[p[i].second]) << '\n';
		}else{
			for(auto x:sett)
				cout << x << ' ';
			cout << '\n';
		}
	}
	return 0;
}