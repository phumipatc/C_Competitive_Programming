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
        if(en!=o.en)    return en<o.en;
        else            return st<o.st;
    }
};
A a[100100];
int main(){
    int n,en,ans=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i].st,&a[i].en);
    sort(a+1,a+n+1);
    en=a[1].en;
    for(int i=2;i<=n;i++){
        if(en<=a[i].st){
            ans++;
            en=a[i].en;
        }
    }
    printf("%d\n",ans);
    return 0;
}
