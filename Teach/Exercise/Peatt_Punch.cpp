/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define height first
#define power second
using namespace std;
typedef long long LL;
stack<pair<int ,int > > st;
vector<int > ans;
int main(){
	ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
	int l,q,h,p;
	cin >> l >> q;
	for(int i=1;i<=l;i++){
		cin >> h;
		while(!st.empty() && st.top().height>=h)	st.pop();
		if(st.empty())	st.push({h,0}),ans.push_back(0);
		else			st.push({h,max(st.top().power,h-st.top().height)}),ans.push_back(max(st.top().power,h-st.top().height));
	}
	sort(ans.begin(),ans.end());
	while(q--){
		cin >> p;
		cout << l-(upper_bound(ans.begin(),ans.end(),p)-ans.begin()) << '\n';
	}
	return 0;
}