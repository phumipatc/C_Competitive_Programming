/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int segment[500500],a[100100],idx=1;
int gcd(int a,int b){
    if(a%b==0)  return b;
    else        return gcd(b,a%b);
}
void build(int l,int r,int now){
    if(l==r){
        segment[now]=a[idx++];
        return ;
    }
    int mid=(l+r)/2;
    build(l,mid,now*2);
    build(mid+1,r,(now*2)+1);
    segment[now]=gcd(segment[now*2],segment[(now*2)+1]);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,n,1);
    return 0;
}
