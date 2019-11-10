/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    char ch;
    int from;
    bool operator < (const A&o) const{
        if(ch<o.ch)   return true;
        else        return false;
    }
};
A b[100100];
int mark[100100];
char a[100100],ansn[100100],anss[100100];
int main()
{
    int n,i,j,sasuke;
    scanf("%d",&n);
    scanf(" %s",a);
    for(i=0;i<n;i++){
        b[i].ch=a[i];
        b[i].from=i;
    }
    sort(b,b+n);
    sasuke=0,j=0;
    for(i=n-1;i>=0;i--){
        while(mark[i]==1)   i--;
        ansn[j]=a[i];
        mark[a[i]]=1;
        while(mark[b[i].from]==1)   sasuke++;
        anss[j]=b[sasuke].ch;
        mark[b[sasuke].from]=1;
        j++;
    }
    printf("%s %s\n",ansn,anss);
    if(strcmp(ansn,anss)<0)    printf("YES\n");
    else                        printf("NO\n");
    printf("%s\n",anss);
    return 0;
}
