/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int s,e;
    bool operator < (const A & o) const{
        if(s<o.s)
            return true;
        else
            return false;
    }
};
A a[10000];
int main(){
    int n,i,ans1=0,ans2=0,st,en;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d %d",&a[i].s,&a[i].e);
    sort(a,a+n);
    st = a[0].s, en= a[0].e;
    for(i=1;i<n;i++){
        if(en >= a[i].s)
            en = max(en, a[i].e);
        else{
            ans1 = max(ans1, en-st);
            ans2 = max(ans2, a[i].s-en);
            st = a[i].s, en= a[i].e;
        }
        printf("%d %d\n",st,en);
    }
    ans1 = max(ans1, en-st);
    printf("%d\n%d\n",ans1,ans2);
    return 0;
}
