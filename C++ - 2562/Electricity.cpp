/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
	int idx,w;
	bool operator < (const A&o) const{
		if(w!=o.w)	return w>o.w;
		else		return idx<o.idx;
	}
};
A now;
priority_queue<A > heap;
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,k,num;
	cin >> n >> k >> num;
	heap.push({1,num});
	for(int i=2;i<=n;i++){
		cin >> num;
		while(!heap.empty() && i-heap.top().idx>k)	heap.pop();
		if(i!=n)
			heap.push({i,num+heap.top().w});
		else
			cout << num+heap.top().w << '\n';
	}
	return 0;
}