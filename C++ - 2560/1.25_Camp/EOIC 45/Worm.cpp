/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    long long d,w;
    bool operator<(const A&o)const{
        return w<o.w;
    }
};
A a[100100];
int main(){
    int n,i;
    long long sum=0,all,watt;
    double ma=-1;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%lld %lld",&a[i].d,&a[i].w);
    sort(a,a+n);
    for(i=0;i<n;i++){
        sum+=a[i].d;
        if((double)sum/(double)a[i].w > ma){
            all = sum;
            watt=a[i].w;
            ma = (double)sum/(double)a[i].w;
        }
    }
    printf("%lld %lld\n",all,watt);
    return 0;
}
