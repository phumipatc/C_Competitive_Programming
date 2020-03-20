/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
	int w,v,d,x,id;
	bool operator < (const A&o) const{
		if(w!=o.w)	return w>o.w;
	}
};
A a;
priority_queue<A > heap;
struct B{
	int w,v,d,x,id;
	bool operator < (const B&o) const{
		return d>o.d;
	}
};
B b;
priority_queue<B > magic;
int mark[200010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,m,opr,typo;
	cin >> n >> m;
	for(int i=1;i<=n+m;i++){
		cin >> opr;
		if(opr == 1){
			cin >> typo;
			a.id = i;
			if(typo == 1){
				cin >> a.w >> a.v;
				a.d = a.x = 0;
				heap.push(a);
			}else if(typo == 2){
				cin >> a.w >> a.v >> a.d;
				a.x = 0;
				heap.push(a);
			}else{
				cin >> a.w >> a.v >> a.d >> a.x;
				heap.push(a);
				magic.push({a.w,a.v,a.d,a.x,a.id});
			}
		}else{
			while(!magic.empty() && magic.top().d<i){
				b = magic.top();
				magic.pop();
				if(mark[b.id])	continue;
				heap.push({b.x,b.v,0,0,b.id});
			}
			while(1){
				if(heap.empty()){
					cout << "0\n";
					break;
				}
				a = heap.top();
				heap.pop();
				if(mark[a.id])	continue;
				if(a.d == 0 && a.x == 0){
					cout << a.v << '\n';
					mark[a.id] = 1;
					break;
				}
				if(a.x == 0){
					if(a.d<i)	continue;
					cout << a.v << '\n';
					mark[a.id] = 1;
					break;
				}
				mark[a.id] = 1;
				cout << a.v << '\n';
				break;
			}
		}
	}
	return 0;
}