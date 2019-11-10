/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long day,value;
    bool operator < (const A&o) const{
        if(day!=o.day)          return day<o.day;
        else if(value!=value)   return value>o.value;
        else                    return value<o.value;
    }
};
A a[100100];
priority_queue< long long> heap;
int main(){
    long long n,i,now=0,ans1=0,ans2=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        scanf("%lld %lld",&a[i].day,&a[i].value);
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++){
        if(heap.size()<a[i].day){
            heap.push(-a[i].value);
        }else if(-heap.top()<a[i].value){
            heap.pop();
            heap.push(-a[i].value);
        }
    }
    while(!heap.empty()){
        ans1-=heap.top();
        ans2++;
        heap.pop();
    }
    printf("%lld\n%lld\n",ans1,ans2);
    return 0;
}
/*
4
1 17
5 15
2 10
2 11

5
2 6
2 5
3 10
4 20
4 15
*/
