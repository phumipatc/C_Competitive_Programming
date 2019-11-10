/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[120],b[120],c[120];
int main()
{
    int n,i;
    char s[120];
    for(i=1;i<=100;i+=3){
        a[i]='A';
        a[i+1]='B';
        a[i+2]='C';
    }
    for(i=1;i<=100;i+=4){
        b[i]='B';
        b[i+1]='A';
        b[i+2]='B';
        b[i+3]='C';
    }
    for(i=1;i<=100;i+=6){
        c[i]='C';
        c[i+1]='C';
        c[i+2]='A';
        c[i+3]='A';
        c[i+4]='B';
        c[i+5]='B';
    }
    int ansa=0,ansb=0,ansc=0,maxx=-1;
    scanf("%d %s",&n,s+1);
    for(i=1;i<=n;i++){
//        printf("%c : %c %c %c\n",s[i],a[i],b[i],c[i]);
        if(s[i]==a[i])  ansa++;
        if(s[i]==b[i])  ansb++;
        if(s[i]==c[i])  ansc++;
        maxx=max(ansa,max(ansb,ansc));
    }
    printf("%d\n",maxx);
    if(ansa==maxx)  printf("Adrian\n");
    if(ansb=maxx)   printf("Bruno\n");
    if(ansc==maxx)  printf("Goran\n");
    return 0;
}
