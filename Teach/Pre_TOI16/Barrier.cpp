/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Sliding Window
	Status	: Finished
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
typedef pair<long long ,long long > PLL;
deque<PII > deq;
int main(){
	int n,k,v,l = 0,sum = 0,maxx = 0;
	scanf("%d %d",&n,&k);
	deq.push_back({0,0});
	for(int i=1;i<=n;i++){
		scanf("%d",&v);
		sum+=v;
		while(!deq.empty() && deq.front().first<i-k)	deq.pop_front();
		while(!deq.empty() && deq.back().second>sum)	deq.pop_back();
		deq.push_back({i,sum});
		if(maxx<deq.back().second-deq.front().second){
			maxx = deq.back().second-deq.front().second;
			l = deq.back().first-deq.front().first;
		}else if(maxx == deq.back().second-deq.front().second)
			l = min(l,deq.back().first-deq.front().first);
	}
	printf("%d\n%d\n",maxx,l);
	return 0;
}