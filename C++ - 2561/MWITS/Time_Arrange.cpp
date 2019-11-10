/*
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
A a[100010];
int main(){
    int n,ans,en;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i].st,&a[i].en);
    sort(a+1,a+n+1);
    en = a[1].en,ans = 1;
    for(int i=2;i<=n;i++){
        if(a[i].st<en)  continue;
        ans++;
        en = a[i].en;
    }
    printf("%d\n",ans);
	return 0;
}
