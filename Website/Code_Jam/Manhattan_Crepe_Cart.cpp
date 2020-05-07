/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int x[100010],y[100010];
pair<int ,int > pos,maxx,maxy;
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int q,n,m;
	char dir;
	cin >> q;
	for(int t=1;t<=q;t++){
		cin >> n >> m;
		while(n--){
			cin >> pos.first >> pos.second >> dir;
			if(dir == 'N'){
				y[pos.second+1]++;
			}else if(dir == 'S'){
				y[0]++;
				y[pos.second]--;
			}else if(dir == 'W'){
				x[0]++;
				x[pos.first]--;
			}else{
				x[pos.first+1]++;
			}
		}
		// printf("0: %d %d\n",x[0],y[0]);
		maxx = {x[0],0};
		maxy = {y[0],0};
		for(int i=1;i<=m;i++){
			x[i]+=x[i-1];
			y[i]+=y[i-1];
			// printf("%d: %d %d\n",i,x[i],y[i]);
			if(maxx.first<x[i])	maxx = {x[i],i};
			if(maxy.first<y[i])	maxy = {y[i],i};
		}
		cout << "Case #" << t << ": " << maxx.second << ' ' << maxy.second << '\n';
		memset(x,0,sizeof x);
		memset(y,0,sizeof y);
	}
	return 0;
}