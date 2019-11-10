/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int num,v;
};
stack<A > st;
int dp[100010];
int main(){
    int n,q,temp;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        while(!st.empty() && st.top().v>temp)   st.pop();
        if(st.empty())  st.push({0,temp}),dp[i] = 0;
        else            st.push({max(temp-st.top().v,st.top().num),temp}),dp[i] = max(temp-st.top().v,st.top().num);
    }
//    for(int i=1;i<=n;i++)   printf("%d ",dp[i]);
    sort(dp+1,dp+n+1);
    while(q--){
        scanf("%d",&temp);
        printf("%d\n",n-(upper_bound(dp+1,dp+n+1,temp)-dp)+1);
    }
	return 0;
}
