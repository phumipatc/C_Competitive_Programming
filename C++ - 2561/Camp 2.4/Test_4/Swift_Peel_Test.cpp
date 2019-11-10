/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int a,b,id;
    bool operator < (const A&o) const{
        if(b!=o.b)  return b<o.b;
        else        return a<o.a;
    }
};
A a[200010];
set<A > sett;
set<A> ::iterator it;
int main(){
    int n,countt = 1,u,v;
    char opr;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %c",&opr);
        if(opr == 'D'){
            scanf("%d %d",&u,&v);
            a[countt] = {u,v,countt};
            sett.insert({u,v,countt++});
        }else{
            scanf("%d",&u);
            it = sett.upper_bound({a[u].a,a[u].b,a[u].id});
            if(it == sett.end())    printf("-1\n");
            else                    printf("%d\n",(*it).id);
        }
    }
	return 0;
}