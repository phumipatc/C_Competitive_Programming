/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
	int u,v,w;
	bool operator < (const A&o) const{
		return w>o.w;
	}
};
A now;
priority_queue<A > heap;
vector<pair<int ,int > > X,Y,Z;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		X.push_back({x,i});
		Y.push_back({y,i});
		Z.push_back({z,i});
	}
	return 0;
}