#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PI;
stack< PI> s;
int main()
{
    long long n,ans=0,i,h;
    scanf("%lld",&n);
    while(n--){
        scanf("%lld",&h);
        PI temp(h,1);
        for(;!s.empty() && s.top().first<=h;s.pop()){
            ans+=s.top().second;
            if(s.top().first==h)
                temp.second+=s.top().second;
        }
        if(!s.empty())
            ans++;
        s.push(temp);
    }
    printf("%lld\n",ans);
    return 0;
}
