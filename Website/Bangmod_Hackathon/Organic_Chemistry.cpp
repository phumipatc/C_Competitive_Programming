/*
	Author	: Phumipat C. [MAGCARI] feat. Wasrek, Aphrodicez
	School	: RYW
	Language: C++
	Algo	: Implement
	Status	: Finished
*/
#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define allst(x,y) (x).begin()+y,(x).end()
#define MOD (LL )(1e9+7)
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
const int MAX_INT = 1e9;
const LL MAX_LL = 1e18;
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
LL modN(LL a,LL b,LL c = MOD){
	if(b == 0)	return 1;
	if(b == 1)	return a%c;
	LL now = modN(a,b/2);
	if(b&1)	return (((now*now)%c)*(a%c))%c;
	else	return (now*now)%c;
}
int check(char c){
	if(c == 'H')	return 1;
	if(c == 'C')	return 12;
	if(c == 'O')	return 16;
	if(c == 'N')	return 14;
	return 0;
}
int n,ch;
string str;
void classify(int i){
	if(ch)	return ;
	if(str.substr(i,3) == "COO"){
		cout << "ester\n";
		ch = 1;
		return ;
	}else if(str.substr(i,2) == "CO"){
		cout << "ketone\n";
		ch = 1;
		return ;
	}else if(str[i] == 'O'){
		cout << "ether\n";
		ch = 1;
		return ;
	}
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int sum = 0;
	cin >> str;
	n = str.length();
	for(int i=0;i<n;i++){
		if(i+1<n && isdigit(str[i+1]))	sum+=(str[i+1]-'0')*check(str[i]);
		else							sum+=check(str[i]);
	}
	cout << sum << '\n';
	cout << "This compound is ";
	if(str.substr(n-4,4) == "COOH"){
		cout << "carboxylic acid\n";
		ch = 1;
		return 0;
	}else if(str.substr(n-5,5) == "CONH2"){
		cout << "amide\n";
		ch = 1;
		return 0;
	}else if(str.substr(n-3,3) == "CHO"){
		cout << "aldehyde\n";
		ch = 1;
		return 0;
	}else if(str.substr(n-3,3) == "NH2"){
		cout << "amine\n";
		ch = 1;
		return 0;
	}else if(str.substr(n-2,2) == "OH"){
		cout << "alcohol\n";
		ch = 1;
		return 0;
	}
	for(int i=0;i<n;i++)
		classify(i);
	return 0;
}