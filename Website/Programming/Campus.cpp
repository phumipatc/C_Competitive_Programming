/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long x,num;
    bool operator < (const A&o) const{
        return x<o.x;
    }
};
A a[500010];
struct B{
    long long y,num;
    bool operator < (const B&o) const{
        return y<o.y;
    }
};
B b[500010];
long long num[500010];
int main(){
    long long n,idx,x,y;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
        scanf("%lld %lld %lld",&a[i].x,&b[i].y,&a[i].num),b[i].num = a[i].num;
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    //X-Axis
    for(long long i=1;i<=n;i++)
        num[i] = a[i].num+num[i-1];
    idx = lower_bound(num+1,num+n+1,(num[n]+1)/2)-num;
    x = a[idx].x;
    //Y-Axis
    memset(num,0,sizeof num);
    for(long long i=1;i<=n;i++)
        num[i] = b[i].num+num[i-1];
    idx = lower_bound(num+1,num+n+1,(num[n]+1)/2)-num;
    y = b[idx].y;
    long long sum = 0;
    for(long long i=1;i<=n;i++)
        sum+=(abs(x-a[i].x)*a[i].num)+(abs(y-b[i].y)*b[i].num);
    printf("%lld\n",sum);
	return 0;
}