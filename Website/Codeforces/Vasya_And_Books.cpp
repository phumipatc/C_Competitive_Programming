/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[200100];
stack<int > st;
int main(){
	freopen("0_in.txt","r",stdin);
	freopen("0_out.txt","w",stdout);
	int n,num,countt;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i>=1;i--)
		st.push(a[i]);
	for(int i=1;i<=n;i++)
		a[i] = 1;
	while(n--){
		scanf("%d",&num);
		countt = 0;
		if(!a[num]){
			printf("%d ",countt);
			continue;
		}
		while(!st.empty() && st.top()!=num){
			countt++;
			a[st.top()] = 0;
			st.pop();
		}
		if(!st.empty()){
			a[st.top()] = 0;
			countt++;
			st.pop();
		}
		printf("%d ",countt);
	}
	return 0;
}
