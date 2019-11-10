/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int st,en;
    bool operator < (const A&o) const{
        if(st!=o.st)    return st<o.st;
        else            return en>o.en;
    }
};
A a[100010];
int main(){
    int q,n,t,v,countt,en,st;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&t);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&a[i].st,&v);
            a[i].en = a[i].st + (v*t);
        }
        sort(a+1,a+n+1);
        en = st = -1,countt = 0;
        for(int i=1;i<=n;i++){
            if(a[i].en<en || (a[i].en == en && a[i].st>st)) continue;
            countt++;
            en = a[i].en;
            st = a[i].st;
        }
        printf("%d\n",countt);
    }
	return 0;
}
