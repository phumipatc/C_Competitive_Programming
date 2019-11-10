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
        return st<o.st;
    }
};
A a[5100];
int main(){
    int n,st,en,ans1 = 0,ans2 = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i].st,&a[i].en);
    sort(a+1,a+n+1);
    st = a[1].st,en = a[1].en;
    for(int i=2;i<=n;i++){
        if(en>=a[i].st)
            en = max(en,a[i].en);
        else{
            ans1 = max(ans1,en-st);
            ans2 = max(ans2,a[i].st-en);
            st = a[i].st,en = a[i].en;
        }
    }
    ans1 = max(ans1,en-st);
    printf("%d\n%d\n",ans1,ans2);
	return 0;
}
