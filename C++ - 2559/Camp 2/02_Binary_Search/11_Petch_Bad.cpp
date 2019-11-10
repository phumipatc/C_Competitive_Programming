/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits//stdc++.h>
using namespace std;
long long a[500200];
int main(){
    long long n,m,i,mid,q,p,sum;
    scanf("%lld %lld",&n,&m);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    p=0;q=1<<30;
    sum=0;
    while(p<q){

        mid=(p+q)/2;
        for(i=0;i<n;i++){
                if(a[i]%mid==0)
                    sum+=a[i]/mid;
                else
                    sum+=(a[i]/mid)+1;
            }
            if(sum<=m)  q=mid;
            else        p=mid+1;
            sum=0;

    }
    printf("%lld",p);

    return 0;
}
