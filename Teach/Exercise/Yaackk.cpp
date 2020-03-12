/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[3][100010],mark[100010];
vector<int > v[3];
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for(int i=0;i<3;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
		}
		
	}
	return 0;
}