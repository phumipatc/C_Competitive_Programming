/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> pint;
vector<pint> V;
inline bool func(pint p,pint q) {
    return p.first*p.second > q.first*q.second;
}
int main() {
    int t,e,v,x,y,i,sum;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&e,&v);
        V=vector<pint>();
        for(i=0;i<v;i++) {
            scanf("%d %d",&x,&y);
            V.push_back(pint(x,y));
        }
        sort(V.begin(),V.end(),func);
        sum=0;
        for(i=0;i<v;i++) {
            sum+=V[i].first*V[i].second;
            if(sum>=e)
                break;
        }
        printf("%d\n",i+1);
    }
    return 0;
}
