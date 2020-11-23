/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: QS
	Status	: Finished
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
typedef pair<long long ,long long > PLL;
LL qs[1000010];
map<LL ,int > mapp;
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,k,maxx = 0;
	string str;
	cin >> n >> k >> str;
	str = "A" + str;
	for(int i=1;i<str.size();i++){
		if(str[i] == 'O')	qs[i] = qs[i-1]+1;
		else				qs[i] = qs[i-1]-k;
		if(!mapp[qs[i]])	mapp[qs[i]] = i;
		maxx = max(maxx,i-mapp[qs[i]]);
		if(qs[i] == 0)	maxx = i;
	}
	cout << maxx << '\n';
	return 0;
}