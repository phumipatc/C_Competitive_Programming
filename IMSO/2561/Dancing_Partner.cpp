/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	int h,v;
};
A a[100100],b[100100];
priority_queue<int> heap;
int dp[100100],dp2[100100];
int main(){
	// freopen("0_in.txt","r",stdin);
	// freopen("0_out.txt","w",stdout);
	int n,idx,idx2;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&a[i].h,&a[i].v);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&b[i].h,&b[i].v);
	idx = idx2 = 1;
	while(idx<=n){
		while(idx2 <= n && a[idx].h>=b[idx2].h){
			heap.push(b[idx2].h+b[idx2].v);
			idx2++;
		}
		if(!heap.empty())	dp[idx] = heap.top();
		else				dp[idx] = -1e9;
		idx++;
	}
	while(!heap.empty())	heap.pop();
	idx = n,idx2 = n;
	while(idx>=1){
		while(idx2>=1 && a[idx].h<b[idx2].h){
			heap.push(b[idx2].v-b[idx2].h);
			idx2--;
		}
		if(!heap.empty())	dp2[idx] = heap.top();
		else				dp2[idx] = -1e9;
		idx--;
	}
	for(int i=1;i<=n;i++){
		//printf("%d %d\n",dp[i],dp2[i]);
		printf("%d\n",max(dp[i]-a[i].h+a[i].v,dp2[i]+a[i].v+a[i].h));
	}
    return 0;
}
