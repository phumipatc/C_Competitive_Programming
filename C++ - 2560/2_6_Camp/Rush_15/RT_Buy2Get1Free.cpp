/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    int n,sum = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sort(a+1,a+n+1);
    for(int i=n-2;i>=1;i-=3)    sum-=a[i];
    printf("%d\n",sum);
    return 0;
}
