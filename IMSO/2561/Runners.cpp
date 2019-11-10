/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int t,v,num;
    bool operator < (const A&o) const{
        if(t!=o.t)  return t<o.t;
        else        return v>o.v;
    }
};
A a[32];
int main(){
    int q,n,m,v,t;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&a[i].v,&t);
            a[i].num = i;
            a[i].t = ((m*1000)/a[i].v)+t;
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)   printf("%d\n",a[i].num);
    }
    return 0;
}
