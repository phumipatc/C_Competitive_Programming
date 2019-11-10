/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    double n,num,sum;
    scanf("%lf",&n);
    for(int i=1;i<=n;i++){
        scanf("%lf",&num);
        sum+=num;
    }
    double ans=round((sum/((n*(n-1))/2)));
    printf("%.0lf\n%.0lf\n",ans,abs((ans*((n*(n-1))/2))-sum));
}
