/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v,w;
    bool operator < (const A & o) const{
        return w>o.w;
    }
};
vector< A> v;
int p[200010];
int findd(int i){
    if(i==p[i])
        return i;
    return p[i]=findd(p[i]);
}
int main()
{
    int n,m,ru,rv,i;
    long long ans=0;
    A temp;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        p[i]=i;
    for(i=0;i<m;i++){
            scanf("%d %d %d",&temp.u,&temp.v,&temp.w);
            v.push_back(temp);
    }
    sort(v.begin(),v.end());
    for(i=0;i<m;i++){
        ru=findd(v[i].u);
        rv=findd(v[i].v);
        if(ru!=rv){
            p[ru]=rv;
            ans+=v[i].w-1;
        }
    }
    printf("%lld\n",ans);
	return 0;
}
