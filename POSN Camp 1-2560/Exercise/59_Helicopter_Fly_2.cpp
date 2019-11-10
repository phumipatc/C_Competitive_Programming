/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int gcd(int m,int n){
    if(m%n==0)  return n;
    return gcd(n,m%n);
}
int main()
{
    int n,m,h;
    scanf("%d %d",&m,&n);
    m--,n--;
    h=gcd(m,n);
    printf("%d",m+n-h);
    return 0;
}
