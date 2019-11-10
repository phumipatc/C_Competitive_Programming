/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[1000100];
int main(){
    int n,t,i;
    long long maxx=-1;
    scanf("%d %d",&n,&t);
    for(i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        maxx=max(maxx,a[i]);
    }
    if(t==1)  printf("-1\n");
    else{
        long long p=0,q=1e15;
        while(p<q){
            long long mid=(p+q)/2,sum=0,countt=0;
            for(i=1;i<=n;i++){
                if(sum>=a[i])
                    sum-=a[i];
                else
                    sum=mid-a[i],countt++;
            }
            if(countt<t+1)          q=mid;
            else if(countt>=t+1)    p=mid+1;
        }
        long long l=max(maxx,(p+q)/2);
        p=0,q=1e15;
        while(p<q){
            long long mid=(p+q)/2,sum=0,countt=0;
            for(i=1;i<=n;i++){
                if(sum>=a[i])
                    sum-=a[i];
                else
                    sum=mid-a[i],countt++;
            }
            if(countt<t)        q=mid;
            else if(countt>=t)  p=mid+1;
        }
        long long r=max(maxx,(p+q)/2);
        printf("%lld\n",r-l);
    }
    return 0;
}
/*
1
6
1 2 3
3 4 8
3 5 4
5 6 7
2 3 4
*/
