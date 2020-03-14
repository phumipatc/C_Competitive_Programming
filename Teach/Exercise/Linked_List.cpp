/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int l[500010],r[500010];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n,k,x,y;
	char opr;
	cin >> n >> k;
	for(int i=0;i<=n;i++)
		l[i] = i-1,r[i] = i+1;
	while(k--){
		cin >> opr >> x >> y;
		//cut x
		r[l[x]] = r[x];
		l[r[x]] = l[x];
		if(opr == 'A'){
			//join x
			r[l[y]] = x;
			l[x] = l[y];
			r[x] = y;
			l[y] = x;
		}else{
			l[r[y]] = x;
			r[x] = r[y];
			l[x] = y;
			r[y] = x;
		}
	}
	int now = r[0];
	for(int i=1;i<=n;i++){
		cout << now << ' ';
		now = r[now];
	}
	return 0;
}