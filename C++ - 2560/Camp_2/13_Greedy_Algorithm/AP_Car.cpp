/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int st,speed,en;
    bool operator < (const A&o) const{
        if(st!=o.st)        return st<o.st;
        else                return en>o.en;
    }
};
A a[100100];
int main()
{
    int i,n,t,q,maxx,st,countt;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&t);
        for(i=0;i<n;i++){
            scanf("%d %d",&a[i].st,&a[i].speed);
            a[i].en=a[i].st+(a[i].speed*t);
        }
        sort(a,a+n);
        maxx=-1,countt=0,st=-1;
        for(i=0;i<n;i++){
//            printf("ST && EN : %d %d\n",a[i].st,a[i].en);
            if(a[i].en<maxx) goto next;
            if(a[i].en==maxx && st<a[i].st) goto next;
            else{
                countt++;
                maxx=a[i].en;
                st=a[i].st;
            }
            next :;

//            printf("MAXX : %d %d\n",maxx,st);
        }
        printf("%d\n",countt);
    }
    return 0;
}
/*
1
5 2
0 10
0 5
10 5
8 8
9 7
*/
