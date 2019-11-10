/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<bits/stdc++.h>
using namespace std;
int modofpower(int a,int b,int c){
    if(b==0)    return 1;
    if(b==1)    return a%c;
    int t=modofpower(a,b/2,c);
    if(b%2==1)
        return (t%c * t%c * a%c)%c;
    return (t%c * t%c)%c;
}
int main()
{
    int a,b,c,q;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d",&a,&b,&c);
        printf("%d\n",modofpower(a,b,c));
    }
    return 0;
}
