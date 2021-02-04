/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char str[110];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q,n;
	cin >> q;
	while(q--){
		cin >> str+1;
		n = strlen(str+1);
		int l = 1,r = n;
		for(;l<=n;l++){
			if(str[l] == '1')
				break;
		}
		for(;r>=1;r--){
			if(str[r] == '1')
				break;
		}
		int countt = 0;
		for(;l<=r;l++)
			countt+=(str[l] == '0');
		cout << countt << '\n';
	}
	return 0;
}