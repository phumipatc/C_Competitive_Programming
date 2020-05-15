/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010],b[100010],tree[100010];
void upd(int idx,int v){
    while(idx<=100003){
        tree[idx]+=v;
        idx+=idx & -idx;
    }
}
int query(int idx){
    int sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-= idx & -idx;
    }
    return sum;
}
int main(){
    int n,num,countt = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&num),b[num] = i;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        upd(i,1);
    for(int i=1;i<=n;i++){
        if(query(b[a[i]]-1))    countt++;
        upd(b[a[i]],-1);
    }
    printf("%d\n",countt);
    return 0;
}