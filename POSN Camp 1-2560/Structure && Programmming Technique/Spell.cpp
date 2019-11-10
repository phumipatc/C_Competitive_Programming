/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,d;
    scanf("%d %d %d",&a,&b,&c);
    d = __gcd(a,b);
    printf((c%d==0)?"Yes":"No");
    return 0;
}
