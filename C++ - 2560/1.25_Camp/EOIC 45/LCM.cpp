/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
long long GCD(long long a,long long b){
    if(a%b==0)
        return b;
    return GCD(b,a%b);
}
int main(){
    long long n,num1,num2,multiply=1;
    scanf("%lld %lld",&n,&num1);
    multiply*=num1;
    n--;
    while(n--){
        scanf("%lld",&num2);
        num1=(num1*num2)/(GCD(num1,num2));
    }
    printf("%lld\n",num1);
return 0;
}
