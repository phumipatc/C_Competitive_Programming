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
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	string str;
	getline(cin,str);
	int n = str.length(),dash = 0,num = 0,alp = 0,dashch = 0;
	for(int i=0;i<n-1;i++)
		dashch = ((str[i] == str[i+1] && str[i] == '-'))?1:dashch;
	for(auto x:str){
		dash+=(x == '-'),num+=isdigit(x);
		if(!isdigit(x) && x!='-')	alp = 1;
	}
	if(n<10){
		cout << "Invalid : too short\n";
		return 0;
	}else if(num>10){
		cout << "Invalid : too many digits\n";
		return 0;
	}else if(str[0]!='0' || (str[1] == '0' || str[1] == '2' || str[1] == '3' || str[1] == '4' || str[1] == '7')){
		cout << "Invalid : wrong prefix\n";
		return 0;
	}else if(alp){
		cout << "Invalid : alphabetic\n";
		return 0;
	}else if(dashch){
		cout << "Invalid : two dashes together\n";
		return 0;
	}else if(str[0] == '-' || str[1] == '-' || str[n-1] == '-'){
		cout << "Invalid : wrong dash position\n";
		return 0;
	}else if(dash>2){
		cout << "Invalid : too many dashes\n";
		return 0;
	}
	cout << "Valid\n";
	return 0;
}