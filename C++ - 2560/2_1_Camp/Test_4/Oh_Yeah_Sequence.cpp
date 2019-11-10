/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[2000100],mark[2000100];
int main(){
    long long i,n,idx,num,sum=0,last=1,opr;
    scanf("%lld",&n);
    while(n--){
        scanf("%lld",&opr);
        if(opr == 1){
            scanf("%lld %lld",&idx,&num);
            mark[idx]+=num;
            sum += idx*num;
        }else if(opr == 2){
            scanf("%lld",&num);
            last++;
            a[last]=num;
            sum += num;
        }else{
            sum -= (a[last]+mark[last]);
            mark[last-1]+=mark[last];
            mark[last]=0;
            last--;
        }
        printf("%lld %lld\n",sum,last);
    }
    return 0;
}
