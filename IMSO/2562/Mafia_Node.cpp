/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
	int v,w;
	bool operator < (const A&o) const{
		if(w!=o.w)	return w<o.w;
		else		return v<o.v;
	}
};
A now;
priority_queue<A > heap;
int p[1000010];
void check(){
	while(!heap.empty()){
		now = heap.top();
		if(now.w!=p[now.v])	heap.pop();
		else				break;
	}
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,l,r,u,v;
	char opr;
	cin >> n >> l >> r;
	l+=r;
	for(int i=1;i<=n;i++)
		heap.push({i,0});
	while(l--){
		cin >> opr;
		if(opr == 'L'){
			cin >> u >> v;
			p[v]++;
			heap.push({v,p[v]});
		}else if(opr == 'C'){
			cin >> u >> v;
			p[v]+=3;
			heap.push({v,p[v]});
		}else if(opr == 'R'){
			check();
			cout << heap.top().v << '\n';
		}else{
			check();
			heap.pop();
		}
	}
	return 0;
}