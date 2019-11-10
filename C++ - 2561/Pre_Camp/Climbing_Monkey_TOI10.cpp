/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int v,w;
    bool operator < (const A&o) const{
        if(w!=o.w)  return w<o.w;
        else        return v<o.v;
    }
};
A a[1000010];
int st[200010],en[200010],banana[200010],normal[200010];
int main(){
    int m,n,k,ans,maxx,ch = 0;
    scanf("%d %d %d",&m,&n,&k);
    for(int i=1;i<=n;i++){
        st[i] = en[i] = i;
        scanf("%d",&banana[i]);
    }
    for(int i=1;i<=k;i++)
        scanf("%d %d",&a[i].v,&a[i].w);
    scanf("%d",&ans);
    sort(a+1,a+k+1);
    for(int i=1;i<=k;i++){
        swap(st[en[a[i].v]],st[en[a[i].v+1]]);
        swap(en[a[i].v],en[a[i].v+1]);
    }
    maxx = banana[st[ans]];
    for(int i=1;i<=n;i++){
        normal[i] = st[i];
        st[i] = en[i] = i;
    }
    for(int i=1;i<=k;i++){
        swap(st[en[a[i].v]],st[en[a[i].v+1]]);
        swap(en[a[i].v],en[a[i].v+1]);
        if(a[i].w == a[i+1].w)  continue;
        if(banana[normal[en[st[ans]+1]]]>maxx){
            maxx = banana[normal[en[st[ans]+1]]];
            ch = 1;
        }
        if(banana[normal[en[st[ans]-1]]]>maxx){
            maxx = banana[normal[en[st[ans]-1]]];
            ch = 1;
        }
    }
    printf("%d\n",maxx);
    if(ch)  printf("USE\n");
    else    printf("NO\n");
	return 0;
}
