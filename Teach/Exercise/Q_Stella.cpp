/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct A{
	LL type,mana,half,last,id;
	bool operator < (const A&o) const{
		if(mana!=o.mana)	return mana<o.mana;
		else				return id>o.id;
	}
};
A now;
priority_queue<A > heap;
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	LL n,mana,half,sum,countt;
	char opr,typo;
	cin >> n;
	sum = countt = 0;
	for(LL i=1;i<=n;i++){
		cin >> opr;
		if(opr == 'c'){
			cin >> typo;
			if(typo == 'n'){
				cin >> mana;
				heap.push({0,mana,0,0,i});
			}else{
				cin >> mana >> half;
				heap.push({1,mana,half,i,i});
			}
		}else{
			while(!heap.empty()){
				now = heap.top();
				heap.pop();
				if(now.type == 0){
					sum+=now.mana;
					break;
				}else{
					if(i-now.last<now.half){
						sum+=now.mana;
						break;
					}
					LL num = (i-now.last)/now.half;
					// now.mana/=(1ll<<num);
					for(int i=1;i<=num;i++)
						now.mana/=2;
					if(now.mana == 0)	continue;
					now.last+=now.half*num;
					heap.push(now);
				}
			}
		}
	}
	while(!heap.empty()){
		now = heap.top();
		heap.pop();
		if(now.type == 1){
			LL num = (n-now.last)/now.half;
			// now.mana/=(1ll<<num);
			for(int i=1;i<=num;i++)
				now.mana/=2;
			if(now.mana == 0)	continue;
			// sum+=now.mana;
			countt++;
			continue;
		}
		// sum+=now.mana;
		countt++;
	}
	cout << sum << '\n' << countt << '\n';
	return 0;
}