/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
int mic[100100];
stack<PII> s;
int main()
{
    int h,n,q,i,pow;
    scanf("%d %d",&n,&q);
    for(i=0;i<n;i++){
        scanf("%d",&h);
        while(!s.empty() && s.top().first>h)  s.pop();
        if(s.empty())   pow=0;
        else            pow=max(s.top().second,h-s.top().first);
        mic[i]=pow;
        s.push(make_pair(h,pow));
    }
    sort(mic,mic+n);
    while(q--){
        scanf("%d",&pow);
        int idx=upper_bound(mic,mic+n,pow)-mic;
        printf("%d\n",n-idx);
    }
    return 0;
}
