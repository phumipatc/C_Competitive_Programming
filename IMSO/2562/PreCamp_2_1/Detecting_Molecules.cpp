/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#include "molecules.h"
#define weight first
#define num second
using namespace std;
typedef long long LL;
std::vector<int> find_subset(int l, int u, std::vector<int> w) {
	vector<pair<int ,int > > v;
	vector<int > ans;
	for(int i=0;i<w.size();i++)
		v.push_back({w[i],i});
	sort(v.begin(),v.end());
	LL sum = 0;
	for(int i=0,j = 0;i<v.size();i++){
		sum+=v[i].weight;
		while(sum>u)	sum-=v[j++].first;
		if(sum>=l && sum<=u){
			for(;j<=i;j++)
				ans.push_back(v[j].second);
			sort(ans.begin(),ans.end());
			break;
		}
	}
    return ans;
}