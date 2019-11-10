/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> PII;
stack<PII> s;
int main()
{
    PII temp;
    long long n,height,ans=0;
    scanf("%lld",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",&height);
        temp.first = height,temp.second = 1;
        while(!s.empty() && s.top().first<=height){
            ans+=s.top().second;
            if(height == s.top().first)
                temp.second+=s.top().second;
            s.pop();
        }
        if(!s.empty())  ans++;
        s.push(temp);
    }
    printf("%lld",ans);
    return 0;
}
