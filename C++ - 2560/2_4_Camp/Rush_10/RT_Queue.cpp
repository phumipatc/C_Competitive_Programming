/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long h,num;
};
A temp;
stack< A> st;
int main(){
    long long n,ans=0;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&temp.h);
        temp.num=1;
        while(!st.empty() && st.top().h<=temp.h){
            ans+=st.top().num;
            if(temp.h==st.top().h)
                temp.num+=st.top().num;
            st.pop();
        }
        if(!st.empty()) ans++;
        st.push(temp);
    }
    printf("%lld\n",ans);
    return 0;
}
