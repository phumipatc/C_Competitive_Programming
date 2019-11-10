/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int l,m;
};
A a[100001],b[100001];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i].l,&a[i].m);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&b[i].l,&b[i].m);
    for(int i=1;i<=n;i++){
        int maxx = -1;
        for(int j=1;j<=n;j++)
            maxx = max(maxx,a[i].m+b[j].m-abs(a[i].l-b[j].l));
        printf("%d\n",maxx);
    }
    return 0;
}
