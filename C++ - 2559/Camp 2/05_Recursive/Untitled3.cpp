/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int A[100100];
int root(int i){
    if(A[i]==i)
        return A[i];
    return A[i]=root(A[i]);
}
int main(){
    int n,m,a,b,ra,rb,i,q;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        A[i]=i;
    while(m--){
        scanf("%d %d",&a,&b);
        ra=root(a);
        rb=root(b);
        A[rb]=ra;
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&a,&b);
        ra=root(a);
        rb=root(b);
        if(ra==rb)
            printf("YES\n");
        else
            printf("NO\n");
    }
return 0;
}
