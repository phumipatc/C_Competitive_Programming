/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    long long x,sum=0,maxx=0;
    scanf("%d",&n);
    while(n--){
        scanf("%lld",&x);
        sum+=x;
        maxx=max(maxx,x);
    }
    printf("%lld\n",max(2*maxx,sum));
    return 0;
}
