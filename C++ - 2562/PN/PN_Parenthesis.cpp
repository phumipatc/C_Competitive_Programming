/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
stack<pair<char ,int > > st;
pair<char ,int > now;
int countt[50010];
int main(){
	int n,ans = 0,all = 0;
	char c;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf(" %c",&c);
		if(c == '('){
			st.push({c,0});
		}else{
			int maxx = 0;
			while(!st.empty()){
				now = st.top();
				st.pop();
				if(now.first == '(')	break;
				maxx = max(maxx,now.second);
			}
			countt[maxx+1]++;
			ans++;
			all = max(all,maxx+1);
			st.push({'_',maxx+1});
		}
	}
	printf("%d\n%d\n",ans,all);
	for(int i=1;i<=all;i++)
		printf("%d ",countt[i]);
	return 0;
}
/*
16
((())(()((()))))
*/