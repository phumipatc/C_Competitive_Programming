/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[100100],n;
void update(int idx,int value){
    while(idx<=100000){
        tree[idx]+=value;
        idx+=idx&(-idx);
    }
}
int query(int idx){
    int sum=0;
    while(idx>0){
        sum+=tree[idx];
        idx-=idx&(-idx);
    }
    return sum;
}
int main(){
    int l,r,i,ans=0,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %d",&l,&r);
        ans=query(l)+query(r);
        printf("%d\n",ans);
        update(l+1,1);
        update(r,-1);
        k=query(l);
        update(l,-k);
        update(l+1,k);
        k=query(r);
        update(r,-k);
        update(r+1,k);
    }

    return 0;
}

