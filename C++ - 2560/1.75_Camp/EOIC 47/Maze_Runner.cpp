/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[15][5100];
int main()
{
    int q,i,len;
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf(" %s",a[i]);
        len=strlen(a[i]);
        if((a[i][len-1]-'0')%2==0)
            printf("EVEN\n");
        else
            printf("ODD\n");
    }
    return 0;
}
