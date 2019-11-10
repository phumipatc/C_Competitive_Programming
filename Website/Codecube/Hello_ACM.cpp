/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int q,m,n,ans,t;
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d %d",&m,&n);
        ans = 0,t = 0;
        while(t+m<n)    t+=20;
        while(t<=n){
            t+=20;
            ans++;
        }
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
