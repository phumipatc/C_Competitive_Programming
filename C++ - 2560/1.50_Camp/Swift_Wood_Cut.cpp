/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int h[1000010];
int main()
{
    long long a,b,sum,i,l,r,mid;
    scanf("%lld %lld",&a,&b);
    for(i=0;i<a;i++)
        scanf("%d",&h[i]);
    l=0,r=10000000000;
    while(l<r){
        mid=(l+r+1)/2,sum=0;
        for(i=0;i<a;i++){
            if(h[i]>mid)
                sum+=h[i]-mid;
        }
        if(sum>=b)  l=mid;
        else           r=mid-1;
    }
    printf("%lld\n",l);
	return 0;
}
