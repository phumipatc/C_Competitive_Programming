/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long c[1000100],su[1000010];
int main(){
    long long p,r,b,mid,a,i,sum,q,temp,sumk,ans=0;
    scanf("%lld %lld",&a,&b);
    for(i=0;i<a;i++)
        scanf("%lld",&c[i]);
        p=0,q=1<<30;

        while(p<q){
           // printf("%lld %lld  ",ans,sum);
            sum=0,temp=0;
            mid=(p+q+1)/2;
           // printf("%lld %lld %lld\n",p,q,mid);
            for(i=0;i<a;i++){
                if(c[i]>=mid)
                    sum+=(c[i]/mid);
            }
            if(temp == mid){  sumk=sum; break;  }
            else if(sum<b){
                q=mid-1;

                if(b-sum<b-ans)
                    ans=sum;
            }else{
                if(sum==b)
                    ans=sum;
                p=mid;
            }
            temp=mid;
        }
        if(ans==b)
            printf("YES\n%lld",p);
        else
            printf("NO\n%lld",p);

    return 0;
    }
