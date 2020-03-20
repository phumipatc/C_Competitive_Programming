/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string a[30010],b[30010];
map<string ,int > mapp;
pair<int ,int > num[30010],temp[30010];
int ans[30010];
void merge_sort(int l,int r){
	if(l == r)	return ;
	int mid = (l+r)/2;
	merge_sort(l,mid);
	merge_sort(mid+1,r);
	int i=l,j=mid+1,k=l;
	while(i<=mid && j<=r){
		if(num[i].first<num[j].first){
			temp[k] = num[i];
			i++,k++;
		}else{
			temp[k] = num[j];
			ans[num[j].second]+=mid-i+1;
			j++,k++;
		}
	}
	while(i<=mid)
		temp[k++] = num[i++];
	while(j<=r)
		temp[k++] = num[j++];
	for(k=l;k<=r;k++)
		num[k] = temp[k];
}
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
		mapp[b[i]] = n-i+1;
	for(int i=1;i<=n;i++)
		num[i] = {mapp[a[i]],i};
	merge_sort(1,n);
	for(int i=1;i<=n;i++)
		cout << ans[i]+1 << '\n';
	return 0;
}
/*
5
GreedyMethod
DivideConquer
Maximumflow
DynamicProgramming
Graph
*/