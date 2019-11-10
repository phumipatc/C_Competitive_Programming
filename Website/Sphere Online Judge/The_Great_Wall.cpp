/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int t,ch;
    bool operator < (const A&o) const{
        return t<o.t;
    }
};
A a[210];
int main(){
    int q,n,sum,ans;
    scanf("%d",&q);
    while(q--){
        ans = sum = 0;
        scanf("%d",&n);
        for(int i=1;i<=2*n;i+=2){
            scanf("%d %d",&a[i].t,&a[i+1].t);
            a[i].ch = 1;
            a[i+1].ch = 2;
        }
        sort(a+1,a+(2*n)+1);
        for(int i=1;i<=2*n;i++){
            if(a[i].ch == 1)    sum++;
            else                sum--;
            ans = max(ans,sum);
        }
        printf("%d\n",ans);
    }
    return 0;
}
