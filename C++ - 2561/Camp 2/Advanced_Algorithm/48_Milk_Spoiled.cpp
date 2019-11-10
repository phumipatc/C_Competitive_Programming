/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int idx,v;
    bool operator < (const A&o) const{
        if(idx!=o.idx)  return idx<o.idx;
        else            return v>o.v;
    }
};
A a[2000010];
int main(){
    int q,countt,sum,n,x,y,z,ans,st,en;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d %d",&n,&x,&y,&z);
        countt = 0;
        ans = sum = n*x;
        for(int i=1;i<=n;i++){
            scanf("%d %d",&st,&en);
            a[countt++] = {st,1};
            a[countt++] = {en+1,2};
        }
        sort(a,a+countt);
        for(int i=0;i<countt;i++){
            if(a[i].v == 1)         sum+=y-x;
            else if(a[i].v == 2)    sum+=z-y;
            ans = max(ans,sum);
        }
        printf("%d\n",ans);
    }
	return 0;
}
