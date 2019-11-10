/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long x,y;
    bool operator < (const A&o) const{
        return y<o.y;
    }
};
A a[100010];
long long b[100010],temp[100010],qs[100010],countt = 0;
void merge_sort(long long l,long long r){
    if(l == r)  return ;
    long long mid = (l+r)/2,i,j,k;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    qs[l-1] = 0;
    for(i=l;i<=r;i++)
        qs[i] = qs[i-1]+b[i];
    i = k = l,j = mid+1;
    while(i<=mid && j<=r){
        if(b[i]<b[j]){
            temp[k++] = b[i++];
        }else{
            countt+=(b[j]*(mid-i+1))+(qs[mid]-qs[i-1]);
            temp[k++] = b[j++];
        }
    }
    while(i<=mid)   temp[k++] = b[i++];
    while(j<=r)     temp[k++] = b[j++];
    for(k=l;k<=r;k++)
        b[k] = temp[k];
}
int main(){
    long long n;
    scanf("%lld",&n);
    for(long long i=1;i<=n;i++)
        scanf("%lld %lld",&a[i].x,&a[i].y);
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++)
        b[i] = a[i].x;
    merge_sort(1,n);
    printf("%lld\n",countt);
	return 0;
}
/*
6
2 1
7 6
9 3
18 4
3 2
5 5
*/