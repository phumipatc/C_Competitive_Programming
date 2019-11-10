/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int gcd(int a,int b){
    if(a%b==0)  return b;
    else        return gcd(b,a%b);
}
int main()
{
    int a,b,c,d;
    scanf("%d %d %d",&a,&b,&c);
    d=gcd(a,b);
    printf((c%d==0)?"Yes":"No");
    return 0;
}
