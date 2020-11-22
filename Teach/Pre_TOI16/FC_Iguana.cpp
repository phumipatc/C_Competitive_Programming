/*
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int ,int > PII;
typedef pair<long long ,long long > PLL;
vector<PII > p;
int main(){
    char col;
    int n,m,a,b,i,sum=0,amount,now,want,ans=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d %d",&a,&b);
        p.push_back({a,1});
        p.push_back({b+1,-1});
    }
    p.push_back({1,0});
    p.push_back({n+1,0});
    sort(p.begin(),p.end());
    scanf(" %c",&col);
    if(col=='R')        want=0;
    else if(col=='G')   want=1;
    else if(col=='B')   want=2;
    for(i=0;i<p.size()-1;i++){
        sum+=p[i].second;
        amount=p[i+1].first-p[i].first;
        now=sum%3;
        ans+=((want-now+3)%3)*amount;
    }
    printf("%d\n",ans);
	return 0;
}
