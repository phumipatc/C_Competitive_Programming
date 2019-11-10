/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000010],A,B,p=0,q=1<<30,mid,r,i,sum;
int main(){
    long long i;
    scanf("%lld %lld",&A,&B);
    for(i=0;i<A;i++)
        scanf("%lld",&a[i]);
    while(p<q){
        sum=0;
        mid=(p+q+1)/2;
        for(i=0;i<A;i++){
            if(a[i]>mid)
                sum+=a[i]-mid;
        }
        if(sum<B)
            q=mid-1;
        else
            p=mid;
    }
    printf("%lld",p);
return 0;
}
