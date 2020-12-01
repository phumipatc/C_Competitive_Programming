/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Infix to Propostfix
	Status	: 
*/
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
LL minN(vector<LL > a){
	LL minn = 1e18;
	for(auto x:a)
		minn = min(minn,x);
	return minn;
}
LL maxN(vector<LL > a){
	LL maxx = -1e18;
	for(auto x:a)
		maxx = max(maxx,x);
	return maxx;
}
stack<char > opr;
stack<int > v;
string str;
void fuse(){
	auto now = opr.top();
	opr.pop();
	auto b = v.top();
	v.pop();
	auto a = v.top();
	v.pop();
	// printf("%d %d %c\n",a,b,now);
	if(now == '1')		v.push((a+b)*104/100);
	else if(now == '2')	v.push((a+b)*108/100);
	else				v.push((a+b)*116/100);
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	cin >> str;
	for(auto x:str){
		if(isupper(x)){
			v.push(20);
		}else if(isdigit(x)){
			while(!opr.empty() && opr.top()!='[' && opr.top()>=x)	fuse();
			opr.push(x);
		}else if(x == '['){
			opr.push(x);
		}else{
			while(opr.top()!='[')	fuse();
			opr.pop();
		}
	}
	while(!opr.empty())	fuse();
	cout << v.top() << '\n';
	return 0;
}