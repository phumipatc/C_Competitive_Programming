/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int ,int > PII;
stack<PII > st;
int dp[100005];
int main(){
    int n,k,num,p;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> num;
        while(!st.empty() && st.top().first>num)   st.pop();
        if(st.empty())  p = 0;
        else            p = max(st.top().second,num-st.top().first);
        st.push(make_pair(num,p));
        dp[i] = p;
    }
    sort(dp,dp+n);
    while(k--){
        cin >> num;
        cout << n-(upper_bound(dp,dp+n,num)-dp) << endl;
    }
    return 0;
}
