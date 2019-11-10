/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int a,b;
    bool operator < (const A&o) const{
        return a>o.a;
    }
};
A info[100100];
int LIS[100100];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&info[i].a,&info[i].b);
    sort(info+1,info+n+1);
    int maxx=0;
    for(int i=1;i<=n;i++){
        int idx=lower_bound(LIS,LIS+maxx,info[i].b)-LIS;
        if(maxx==idx)    maxx++;
        LIS[idx]=info[i].b;
    }
    printf("%d\n",maxx);
    return 0;
}
