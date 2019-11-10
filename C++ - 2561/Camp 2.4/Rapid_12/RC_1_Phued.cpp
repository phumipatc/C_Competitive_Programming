/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],l[100010],r[100010];
int tree[100010];
void update(int idx,int v){
    while(idx<=100003){
        tree[idx] = max(tree[idx],v);
        idx+=idx & -idx;
    }
}
int query(int idx){
    int maxx = 0;
    while(idx>0){
        maxx = max(maxx,tree[idx]);
        idx-= idx & -idx;
    }
    return maxx;
}
int main(){
    int n,idx,ans = 0,q;
    scanf("%d",&q);
    while(q--){
        ans = 0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),b[i] = a[i];
        sort(b+1,b+n+1);
        a[n+1] = 0;
        for(int i=1;i<=n;i++){
            if(a[i]>a[i-1]) l[i] = l[i-1]+1;
            else            l[i] = 1;
        }
        for(int i=n;i>=1;i--){
            if(a[i]<a[i+1]) r[i] = r[i+1]+1;
            else            r[i] = 1;
        }
        for(int i=1;i<=n;i++){
            idx = upper_bound(b+1,b+n+1,a[i]-1)-b-1;
            ans = max(ans,query(idx)+r[i]);
            idx = lower_bound(b+1,b+n+1,a[i])-b;
            update(idx,l[i]);
        }
        printf("%d\n",ans);
        memset(l,0,sizeof l);
        memset(r,0,sizeof r);
        memset(tree,0,sizeof tree);
    }
	return 0;
}
/*
8
1 2 5 4 3 7 6 9
*/