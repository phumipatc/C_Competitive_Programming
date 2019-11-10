#include<bits/stdc++.h>
using namespace std;
int gcd(int m,int n){
    int a;
    for(int i=1;i<=m && i<=n;i++)
        if(m%i==0 && n%i == 0 )
            a=i;
    return a;
}
int main()
{
    int n,m,h;
    scanf("%d %d",&m,&n);
    m=m-1,n=n-1;
    h=gcd(m,n);
    printf("%d",m+n-h);
    return 0;
}
