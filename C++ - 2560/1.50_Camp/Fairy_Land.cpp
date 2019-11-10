/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int p[100100];
int findd(int i){
    if(p[i]==i)
        return i;
    return p[i]=findd(p[i]);
}
int main()
{
    int n,m,r,s,q,i;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        p[i]=i;
    while(m--){
        scanf("%d %d",&r,&s);
        p[findd(s)]=findd(r);
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&r,&s);
        if(findd(r)==findd(s))
            printf("YES\n");
        else
            printf("NO\n");
    }
	return 0;
}
