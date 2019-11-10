/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int st,en;
    bool operator < (const A&o) const{
        if(en!=o.en)    return en>o.en;
        else            return st<o.st;
    }
};
A a[100001];
int LIS[100001],arr[100001];
int main(){
    int n,maxx=0,idx;
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i].st,&a[i].en);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        arr[i]=a[i].st;
    for(int i=1;i<=n;i++){
        idx=upper_bound(LIS,LIS+maxx,arr[i])-LIS;
        if(idx==maxx)   maxx++;
        LIS[idx]=arr[i];
    }
    printf("%d\n",maxx);
    return 0;
}
