/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,pos;
    bool operator < (const A&o) const{
        if(v!=o.v)  return v<o.v;
        else        return pos>o.pos;
    }
};
A a[1000010];
int main(){
    int n,st;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].v);
        a[i].pos = i;
    }
    sort(a+1,a+n+1);
    st = 1;
    for(int i=1;i<=n;i++){
        if(a[i].v!=a[i+1].v){
            printf("%d %d\n",a[i].v,max(abs(st-a[st].pos),abs(i-a[i].pos)));
            st = i+1;
        }
    }
	return 0;
}
