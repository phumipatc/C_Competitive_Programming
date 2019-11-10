/*
    Task    : RT God Of TOI 1
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],c[100010],tree[100010];
void update(int idx,int val){
    while(idx<=100000){
        tree[idx]+=val;
        idx+=(idx&(-idx));
    }
}
int query(int idx){
    int sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}
int main(){
    int idx = 0,n,m,p = 0,q = -1e9,mid,countt,now;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i] = a[i];
        q = max(q,a[i]);
    }
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++){
        if(b[i] == b[i+1])  continue;
        c[idx++] = b[i];
    }
    while(p<q){
        mid = (p+q)/2,countt = 0;
        for(int i=1;i<=n;i++){
            if(a[i]>mid)    continue;
            now = lower_bound(c,c+idx,a[i])-c+1;
            countt+=(query(n)-query(now-1));
            update(now,1);
        }
        memset(tree,0,sizeof tree);
        if(countt<m)    p = mid+1;
        else            q = mid;
    }
    printf("%d\n",p);
    return 0;
}
