/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1510],dp[1510][110],tree[2][1000010];
priority_queue<int > l,r;
void update(int idx,int pos,int v){
	while(idx<=1000003){
		tree[pos][idx]+=v;
		idx+= idx & -idx;
	}
}
int query(int idx,int pos){
	int  sum = 0;
	while(idx>0){
		sum+=tree[pos][idx];
		idx-= idx & -idx;
	}
	return sum;
}
int main(){
    int n,k,med,countt;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<=n;i++)
        for(int j=0;j<=k;j++)
            dp[i][j] = 1e9;
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			update(a[j],0,1);
			update(a[j],1,a[j]);

			if(l.empty()){
				l.push(a[j]);
			}else{
				if(l.size()>r.size()){
					if(a[j]>=l.top())	r.push(-a[j]);
					else				r.push(-l.top()),l.pop(),l.push(a[j]);
				}else if(r.size()>l.size()){
					if(a[j]<=-r.top())	l.push(a[j]);
					else				l.push(-r.top()),r.pop(),r.push(-a[j]);
				}else{
					if(a[j]<=-r.top())	l.push(a[j]);
					else				r.push(-a[j]);
				}
			}
			if((j-i+1)%2){
				if(l.size()>r.size())	med = l.top();
				else					med = -r.top();
			}else						med = (l.top()-r.top())/2;
			
			countt = query(med-1,0)*med - (query(1000000,0)-query(med,0))*med;
			countt+= (query(1000000,1)-query(med,1)) - query(med-1,1);
			// printf("%d %d : %d %d\n",i,j,med,countt);
			for(int l=1;l<=k;l++)
				dp[j][l] = min(dp[j][l],dp[i-1][l-1]+countt);
		}
		for(int j=i;j<=n;j++){
			update(a[j],0,-1);
			update(a[j],1,-a[j]);
		}
		while(!l.empty())	l.pop();
		while(!r.empty())	r.pop();
    }
    printf("%d\n",dp[n][k]);
	return 0;
}
/*
countt = query(av-1,0)*av - (maxx-query(av,0))*av;
countt+= (maxxx-query(av,1)) - query(av-1,1);
*/