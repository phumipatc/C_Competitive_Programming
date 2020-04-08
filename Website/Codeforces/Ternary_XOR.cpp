/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[50010],b[50010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q,n,ch;
	char num;
	cin >> q;
	while(q--){
		cin >> n >> num;
		ch = 0;
		a[1] = b[1] = 1;
		for(int i=2;i<=n;i++){
			cin >> num;
			if(num == '0'){
				a[i] = b[i] = 0;
			}else if(num == '1'){
				if(ch){
					b[i] = 1;
					a[i] = 0;
				}else{
					ch = 1;
					b[i] = 0;
					a[i] = 1;
				}
			}else if(num == '2'){
				if(ch){
					a[i] = 0;
					b[i] = 2;
				}else{
					a[i] = b[i] = 1;
				}
			}
		}
		for(int i=1;i<=n;i++)
			cout << a[i];
		cout << '\n';
		for(int i=1;i<=n;i++)
			cout << b[i];
		cout << '\n';
	}
	return 0;
}