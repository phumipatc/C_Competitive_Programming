/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
stack<int > st;
char a[110];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int q;
    cin >> q;
    while(q--){
        cin >> a+1;
        int n = strlen(a+1);
        for(int i=1;i<=n;i++){
            if(a[i] == ')'){
                int num = 0;
                while(!st.empty() && st.top()!=-1){
                    num+=st.top();
                    st.pop();
                }
                st.pop();
                st.push(num);
            }else{
                if(a[i] == '('){
                    st.push(-1);
                    continue;
                }
                if(isdigit(a[i])){
                    st.top()*=(a[i]-'0');
                    continue;
                }
                if(a[i] == 'H')         st.push(1);
                else if(a[i] == 'C')    st.push(12);
                else                    st.push(16);
            }
        }
        int num = 0;
        while(!st.empty()){
            num+=st.top();
            st.pop();
        }
        cout << num << "\n";
    }
    return 0;
}