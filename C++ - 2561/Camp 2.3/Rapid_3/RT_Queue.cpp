/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long h,num;
};
stack< A> st;
int main(){
    long long n,ans = 0,h,num;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&h);
        num = 1;
        while(!st.empty() && st.top().h<=h){
            ans+=st.top().num;
            if(h == st.top().h) num+=st.top().num;
            st.pop();
        }
        if(!st.empty()) ans++;
        st.push({h,num});
    }
    printf("%lld\n",ans);
    return 0;
}
