/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
stack<int > st;
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int q,n,num,now;
    cin >> q;
    while(q--){
        cin >> n;
        now = 1;
        for(int i=1;i<=n;i++){
            cin >> num;
            while(!st.empty() && st.top() == now){
                now++;
                st.pop();
            }
            if(num == now){
                now++;
                continue;
            }
            // printf("%d %d\n",now,num);
            st.push(num);
        }
        while(!st.empty() && st.top() == now){
                now++;
                st.pop();
            }
        if(now == n+1)  cout << "yes" << "\n";
        else            cout << "no" << "\n";
        while(!st.empty())  st.pop();
    }
    return 0;
}