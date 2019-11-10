/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
stack< int> st;
int a[100010];
int main(){
    int q,n,ans,now;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        ans = 0;
        for(int i=1;i<=n;i++){
            scanf("%d",&now);
            while(!st.empty() && now>st.top())  	st.pop();
            if(now == a[i])                     	st.push(now);
            else if(!st.empty() && now == st.top())	continue;
            else									st.push(now),ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
