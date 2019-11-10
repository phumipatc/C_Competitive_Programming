/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long x,y;
    bool operator < (const A&o) const{
        if(x!=o.x)  return x<o.x;
        return y>o.y;
    }
};
A a[1000100];
struct B{
    long long x,y;
    bool operator < (const B&o) const{
        if(x!=o.x)  return x<o.x;
        return y<o.y;
    }
};
B b[1000100];
int main()
{
    long long n,i,j,maxx=0,high;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
        scanf("%lld %lld",&a[i].x,&a[i].y);
    sort(a,a+n);
    high = a[n-1].y;
    b[maxx].x = a[n-1].x;
    b[maxx].y = a[n-1].y;
    maxx++;
    for(i=n-2;i>=0;i--){
        if(a[i].y >= high){
            b[maxx].x = a[i].x;
            b[maxx].y = a[i].y;
            maxx++;
            high = a[i].y;
        }

    }
    sort(b,b+maxx);
    for(i=0;i<maxx;i++){
        printf("%lld %lld\n",b[i].x,b[i].y);
    }
    return 0;
}
/*
5
9 1
8 2
7 3
6 4
5 5

7
1 2
2 4
4 1
7 3
5 5
6 6
3 7
*/
