/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 2007
using namespace std;
struct A{
    int v,type;
    bool operator < (const A&o) const{
        if(v!=o.v)  return v<o.v;
        else        return type<o.type;
    }
};
A a[100100];
int q[100100];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=2*n;i+=2){
        scanf("%d %d",&a[i].v,&a[i+1].v);
        a[i].type = 1;
        a[i+1].type = -1;
    }
    sort(a+1,a+(2*n)+1);
    for(int i=1;i<=m;i++)
        scanf("%d",&q[i]);
    sort(q+1,q+m+1);
    int idx = 1,sum = 0,ans = 0;
    for(int i=1;i<=m;i++){
        while(a[idx].v<q[i] && idx<=2*n){
            sum+=a[idx].type;
            idx++;
        }
        while(a[idx].v == q[i] && a[idx].type == -1){
            sum--;
            idx++;
        }
        ans+=sum;
        ans%=MOD;
    }
    printf("%d\n",ans);
    return 0;
}
