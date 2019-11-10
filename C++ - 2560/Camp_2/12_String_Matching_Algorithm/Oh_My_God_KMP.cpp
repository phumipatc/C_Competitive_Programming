/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1000100],b[1000100];
int pi[1000100];
int main()
{
    int i,j=0,lena,lenb;
    scanf(" %s %s",a+1,b+1);
    lena=strlen(a+1);
    lenb=strlen(b+1);
    for(i=2;i<=lenb;i++){
//        printf("%c %c",b[j+1],b[i]);
        while(j>0 && b[j+1]!=b[i])  j=pi[j];
        if(b[j+1]==b[i])    j++;
        pi[i]=j;
//        printf(" %d\n",pi[i]);
    }
//    printf("\n");
    for(i=1,j=0;i<=lena;i++){
//        printf("%c %c",b[j+1],a[i]);
        while(j>0 && b[j+1]!=a[i])  j=pi[j];
        if(b[j+1]==a[i])    j++;
        if(j==lenb){
            printf("Lucky\n");
            return 0;
        }
//        printf(" %d\n",j);
    }
    printf("Unlucky\n");
    return 0;
}
