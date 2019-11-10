/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int st[50100],en[50100];
int main()
{
    int n,m,i,pos,countt=0,s,e;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)   scanf("%d %d",&st[i],&en[i]);
    sort(st,st+n);
    sort(en,en+n);
    while(m--){
        scanf("%d",&pos);
        e=upper_bound(en,en+n,pos)-en;
        s=lower_bound(st,st+n,pos)-st;
        countt+=s-e;
        countt%=2007;
//        printf("u: %d\nl: %d\ncountt: %d\n",s,e,countt);
    }
    printf("%d\n",countt);
    return 0;
}
/*
4 5
10 30
5 15
1 15
5 50
5
12
15
40
80
*/
