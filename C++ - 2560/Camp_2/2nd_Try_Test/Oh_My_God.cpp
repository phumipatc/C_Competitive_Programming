/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1000100],b[1000100];
int last[1000100];
int main()
{
    int lena,lenb,i,j;
    scanf(" %s %s",a+1,b+1);
    lena=strlen(a+1);
    lenb=strlen(b+1);
    j=0;
    for(i=2;i<=lenb;i++){
        while(j>0 && b[j+1]!=b[i])  j=last[j];
        if(b[j+1]==b[i])    j++;
        last[i]=j;
    }
    for(i=1,j=0;i<=lena;i++){
        while(j>0 && b[j+1]!=a[i])  j=last[j];
        if(b[j+1]==a[i])    j++;
        if(j==lenb){
            printf("Lucky\n");
            return 0;
        }
    }
    printf("Unlucky\n");
    return 0;
}
