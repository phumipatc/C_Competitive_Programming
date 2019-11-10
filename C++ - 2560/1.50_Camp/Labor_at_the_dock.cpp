/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000010],n,m,sum,p,q,mid,mi=1<<30;
int main(){
    int i;
    scanf("%lld %lld",&n,&m);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
        mi=min(mi,a[i]);
    }
    p=0;
    q=mi*m;
    while(p<q){
        mid=(p+q)/2;
        for(i=0,sum=0;i<n;i++)
            sum+=mid/a[i];
        if(sum>=m)  q=mid;
        else        p=mid+1;
    }
    printf("%lld",p);
return 0;
}
