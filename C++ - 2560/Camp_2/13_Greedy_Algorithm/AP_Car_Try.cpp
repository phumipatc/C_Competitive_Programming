/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int st,en;
    bool operator < (const A&o) const{
        if(st!=o.st)    return st<o.st;
        else            return en>o.en;
    }
};
A a[100100];
int main()
{
    int q,i,n,t,speed,s,maxx,countt;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&t);
        for(i=0;i<n;i++){
            scanf("%d %d",&a[i].st,&speed);
            a[i].en=a[i].st+(speed*t);
        }
        sort(a,a+n);
        maxx=s=-1,countt=0;
        for(i=0;i<n;i++){
            if(a[i].en<maxx || (a[i].en==maxx && a[i].st>s))    goto next;
            countt++;
            maxx=a[i].en;
            s=a[i].st;
            next: ;
        }
        printf("%d\n",countt);
    }
    return 0;
}
