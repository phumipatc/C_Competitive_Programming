/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int l,r;
};
A a[100100];
int ans;
void merge_sort(int l,int r){
    if(l == r)  return ;
    int mid=(l+r)/2,p=l,q=r,idx=l;
    merge_sort(1,mid);
    while(p <= mid && q <= r){
        if(a[p]>a[q])
    }
    while(p<=mid)   b[idx++]=a[p++];
    while(q<=r)     b[idx++]=a[q++];
    for(int i=l;i<=r;i++)
        a[i]=b[i];
}
int main(){
    int n,l,r,idx=1;
    scanf("%d",&n);
    lv[1]=1;
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a[i].l,&a[i].r);
    }
    merge_sort(1,n+1);
    printf("%d\n",ans);
    return 0;
}
