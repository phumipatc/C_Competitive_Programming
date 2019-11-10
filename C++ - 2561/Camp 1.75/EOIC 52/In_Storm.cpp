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
        return w>o.w;
    }
};
A a[1000010];
int ans[1000010];
int main(){
    int n,now;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i].w);
        a[i].v = i;
    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        if(a[i].v>a[1].v){
            for(int j=a[i].v;j>a[1].v;j--){
                if(ans[j]>=a[i].w)  break;
                ans[j] = a[i].w;
            }
        }else{
            for(int j=a[i].v;j<a[1].v;j++){
                if(ans[j]>=a[i].w)  break;
                ans[j] = a[i].w;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(i == a[1].v) continue;
        printf("%d ",ans[i]);
    }
	return 0;
}
