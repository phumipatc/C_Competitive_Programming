/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,long long> > p;
int main(){
    long long a,b,s,e,i,sum=0;
    scanf("%lld %lld",&a,&b);
    for(i=0;i<a;i++){
        scanf("%lld %lld",&s,&e);
        if(s<e) continue;
        p.push_back(make_pair(e,s));
    }
    sort(p.begin(),p.end());
    s=0,e=0;
    for(i=0;i<(int)p.size();i++){
        if(p[i].first>e){
            sum+=e-s;
            s=p[i].first,e=p[i].second;
        }else
            e=max(e,p[i].second);
    }
    sum+=e-s;
    printf("%lld\n",b+2*sum);
return 0;
}
