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
    int ch=0,num,i,j,k,n;
    scanf("%d",&num);
    n=num;
    while(n>1){
        k=n%10;
        if(k==0)
            ch=1;
        n/=10;
    }
    if(ch==0){
        printf("-1\n");
        return 0;
    }
    return 0;
}
