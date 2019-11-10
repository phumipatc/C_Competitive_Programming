/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[3010],b[3010],LIS[3010];
pair<int ,int > p[3010];
int main(){
	freopen("0_in.txt","r",stdin);
	freopen("0_out.txt","w",stdout);
	int n,idx,num;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num);
		p[num].first = i;
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&num);
		p[num].second = i;
	}
	sort(p+1,p+n+1);
	num = 0;
	for(int i=1;i<=n;i++){
		idx = upper_bound(LIS,LIS+num,p[i].second)-LIS;
		if(idx == num)	num++;
		LIS[idx] = p[i].second;
	}
	printf("%d\n",num);
	return 0;
}
