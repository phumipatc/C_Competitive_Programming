/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long st,en,weight;
    bool operator < (const A&o) const{
        if(weight>o.weight) return true;
        else                return false;
    }
};
A a[1000100];
long long p[200100];
long long froot(long long i){
    if(p[i]==i) return i;
    return p[i]=froot(p[i]);
}
int main()
{
    long long n,m,i,ans=0;
    scanf("%lld %lld",&n,&m);
    for(i=0;i<m;i++)
        scanf("%lld %lld %lld",&a[i].st,&a[i].en,&a[i].weight);
    sort(a,a+m);
    for(i=1;i<=n;i++)
        p[i]=i;
    for(i=0;i<m;i++){
////        printf("start : %lld end : %lld father st: %lld father end: %lld\n",a[i].st,a[i].en,froot(p[a[i].st]),froot(p[a[i].en]));
        if(froot(p[a[i].st])!=froot(p[a[i].en])){
            p[froot(a[i].st)]=p[froot(a[i].en)];
            ans+=a[i].weight-1;
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
