/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string str;
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int ch = 0;
	cin >> str;
	for(auto x:str){
		if(islower(x))	ch|=1;
		if(isupper(x))	ch|=2;
	}
	if(ch == 1)			cout << "All Small Letter\n";
	else if(ch == 2)	cout << "All Capital Letter\n";
	else				cout << "Mix";
	return 0;
}