/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int p[100100];
int findroot(int i){
    if(p[i]==i) return i;
    return p[i]=findroot(p[i]);
}
int main()
{
    int n,k,q,i,roota,rootb,a,b;
    scanf("%d %d %d",&n,&k,&q);
    for(i=1;i<=n;i++)   p[i]=i;
    for(i=0;i<k;i++){
        scanf("%d %d",&a,&b);
        roota=findroot(a);
        rootb=findroot(b);
        if(roota!=rootb)
            p[rootb]=roota;
    }
    while(q--){
        scanf("%d %d",&a,&b);
        roota=findroot(a);
        rootb=findroot(b);
        if(roota==rootb)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
