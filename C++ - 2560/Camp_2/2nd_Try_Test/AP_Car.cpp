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
        return en>o.en;
    }
};
A a[100100];
int main()
{
    int q,n,t,i,v,en,st,ans;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&t);
        for(i=0;i<n;i++){
            scanf("%d %d",&a[i].st,&v);
            a[i].en=(v*t)+a[i].st;
        }
        sort(a,a+n);
        st=en=-1,ans=0;
        for(i=0;i<n;i++){
            if(en>a[i].en)  goto next;
            else if(en==a[i].en && st<a[i].st)  goto next;
            else{
                ans++;
                en=a[i].en;
                st=a[i].st;
            }
            next :;
        }
        printf("%d\n",ans);
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
