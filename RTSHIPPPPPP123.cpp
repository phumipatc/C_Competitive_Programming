#include<bits/stdc++.h>
using namespace std;
struct A{
    long long h,to,ba;
};
long long a[100100],b[100100];
stack<A>st;
int main(){
    long long h,to,ba,i,n,ans=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(i=1;i<=n;i++) scanf("%lld",&b[i]);
    a[0]=1;
    b[0]=1;
    for(i=n;i>=0;i--){
        h=a[i],to=0,ba=0;
        while(!st.empty()&&st.top().h>a[i]){
            ans+=(st.top().to*(st.top().h-h)*b[i]);
             //printf("%lld ",ans);
            ans+=(b[i]*(((st.top().h-1-h)*(st.top().h-h))/2))*st.top().ba;
            //printf("%lld\n",ans);
            ba+=st.top().ba;
            to+=st.top().to+(st.top().ba*(st.top().h-a[i]));
            st.pop();
        }
        st.push({h,to+1,ba+1});

    }
    printf("%lld",ans);
return 0;
}
