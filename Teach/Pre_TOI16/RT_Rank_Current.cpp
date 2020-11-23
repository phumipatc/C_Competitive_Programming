/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: FW
	Status	: Finished
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
typedef pair<long long ,long long > PLL;
struct A{
	int opr,v;
};
A a[300010];
map<int ,int > mapp;
vector<int > comp;
int tree[300010];
void upd(int idx,int v){
	while(idx<=300003){
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
	int n;
	cin >> n;
	comp.push_back(0);
	for(int i=1;i<=n;i++){
		cin >> a[i].opr >> a[i].v;
		if(a[i].opr == 1)	comp.push_back(a[i].v);
	}
	sort(comp.begin(),comp.end());
	for(int i=1;i<comp.size();i++)
		mapp[comp[i]] = i;
	for(int i=1;i<=n;i++){
		if(a[i].opr == 1){
			upd(mapp[a[i].v],1);
		}else{
			cout << query(mapp[a[i].v]) << '\n';
		}
	}
	return 0;
}