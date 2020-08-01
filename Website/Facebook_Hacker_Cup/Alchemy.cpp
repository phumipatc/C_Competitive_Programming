/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int q,n,a,b;
	string str;
	cin >> q;
	for(int z=1;z<=q;z++){
		cin >> n >> str;
		a = b = 0;
		for(auto x:str){
			if(x == 'A')	a++;
			else			b++;
		}
		cout << "Case #" << z << ": " << ((abs(a-b)<=1)?"Y\n":"N\n");
		str.clear();
	}
	return 0;
}