/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
	int w,v;
	bool operator < (const A&o) const{
		return w>o.w;
	}
};
priority_queue<A > heap;
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,w,v;
	char opr;
	cin >> n >> w;
	n+=w;
	while(n--){
		cin >> opr;
		if(opr == 'T'){
			cin >> w >> v;
			heap.push({w,v});
		}else{
			if(heap.empty()){
				cout << "0\n";
				continue;
			}
			cout << heap.top().v << '\n';
			heap.pop();
		}
	}
	return 0;
}