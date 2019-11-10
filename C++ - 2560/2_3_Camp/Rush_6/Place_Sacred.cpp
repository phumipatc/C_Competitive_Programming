/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long u,v,w;
    bool operator < (const A&o) const{
        if(w>o.w) return true;
        else      return false;
    }
};
A a[1000100];
long long p[200100];
long long find_root(long long i){
    if(p[i]==i) return i;
    return p[i]=find_root(p[i]);
}
int main()
{
    long long n,m,i,ans=0;
    scanf("%lld %lld",&n,&m);
    for(i=0;i<m;i++)
        scanf("%lld %lld %lld",&a[i].u,&a[i].v,&a[i].w);
    sort(a,a+m);
    for(i=1;i<=n;i++)
        p[i]=i;
    for(i=0;i<m;i++){
        int ru=find_root(p[a[i].u]);
        int rv=find_root(p[a[i].v]);
        if(ru!=rv){
            p[ru]=p[rv];
            ans+=a[i].w-1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
4 6
1 2 1
3 4 1
1 3 2
4 1 3
2 3 2
3 1 1

6 9
1 2 8
2 3 6
1 4 6
4 2 6
4 5 8
2 5 7
5 6 5
2 6 9
3 6 5
*/
