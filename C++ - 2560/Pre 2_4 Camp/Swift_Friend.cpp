/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
deque< int> deq;
vector< int> name[25];
char str[25];
int main(){
    long long n,ans=0,k;
    scanf("%lld %lld",&n,&k);
    for(long long i=1;i<=n;i++){
        scanf(" %s",str);
        long long len=strlen(str);
        name[len].push_back(i);
    }
    for(long long i=1;i<=20;i++){
        for(long long j=0;j<name[i].size();j++){
            while(!deq.empty() && deq.front()<name[i][j]-k) deq.pop_front();
            deq.push_back(name[i][j]);
            ans+=deq.size()-1;
        }
        deq.clear();
    }
    printf("%lld\n",ans);
    return 0;
}
