/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int st[1000100],en[1000100];
int main(){
    int n,q,a,b,i,maxx=0;
    scanf("%d",&n);
    memset(st,0,sizeof st);
    memset(en,0,sizeof en);
    for(i=0;i<n;i++){
        scanf("%d %d",&a,&b);
        st[a]=1;
        en[b]=1;
        if(b>maxx)
            maxx=b;
    }
    for(i=1;i<=maxx;i++){
        st[i]+=st[i-1];
        en[i]+=en[i-1];
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&a,&b);
        printf("%d\n",st[b]-en[a-1]);
    }
return 0;
}
