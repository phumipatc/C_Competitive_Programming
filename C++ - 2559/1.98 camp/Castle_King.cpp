/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long a[550000];
long long n,i,max=0,total=0,temp=0;
int main(){
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
        total+=a[i];
    }
    sort(a,a+n);
    for(i=1;i<n;i++){
        if(a[i]>a[i-1])
            temp+=(a[i]-a[i-1]);
    }
    printf("%lld",(total*2) + a[0] + a[n-1] + n + temp);
return 0;
}
