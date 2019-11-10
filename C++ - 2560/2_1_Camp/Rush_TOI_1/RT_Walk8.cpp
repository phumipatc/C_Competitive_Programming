/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long x1,x2,y1,y2,p;
};
A a[200100];
int main()
{
    long long i,n,x1,x2,y1,y2,sum=0,maxx=-1;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> x1 >> y1 >> a[i].p;
        a[i].x1=x1-a[i].p,a[i].x2=x1+a[i].p;
        a[i].y1=y1-a[i].p,a[i].y2=y1+a[i].p;
    }
    x1=a[0].x1,x2=a[0].x2,y1=a[0].y1,y2=a[0].y2;
    for(i=1;i<n;i++){
        maxx = max(a[i].x1-x2,max(x1-a[i].x2,max(a[i].y1-y2,y1-a[i].y2)));
        if(maxx<0)  maxx=0;
        x1 -= maxx,x2 += maxx;
        x1 = max(x1,a[i].x1);
        x2 = min(x2,a[i].x2);
        y1 -= maxx,y2 += maxx;
        y1 = max(y1,a[i].y1),y2 = min(y2,a[i].y2);
        sum += maxx;
    }
    printf("%lld\n",sum);
    return 0;
}
