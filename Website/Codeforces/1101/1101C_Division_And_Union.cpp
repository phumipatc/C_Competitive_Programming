/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int l,r,id;
    bool operator < (const A&o) const{
        if(l!=o.l)  return l<o.l;
        else        return r<o.r;
    }
};
A a[100010];
int ans[100010];
int main(){
    int q,now,n,ch;
    scanf("%d",&q);
    while(q--){
        ch = 1,now = 1;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d %d",&a[i].l,&a[i].r);
            a[i].id = i;
        }
        sort(a,a+n);
        for(int i=0;i<n-1;i++){
            printf("%d %d\n",a[i].l,a[i].r);
            if(i<=n-3){
                if(a[i+2].l<=a[i].r){
                    ch = 0;
                    break;
                }
            }
            ans[a[i].id] = now;
            now = 3-now;
        }
        if(ch == 0)
            printf("-1\n");
        else{
            for(int i=0;i<n;i++)
                printf("%d ",ans[i]);
            printf("\n");
        }
    }
	return 0;
}
