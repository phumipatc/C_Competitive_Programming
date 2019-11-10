/*
    Task :
    Author : Boss
    School : RYW
    Language : C
*/
#include<stdio.h>
#include<ctype.h>
char a[200],b[200];
int main()
{
    int n,k,p,i,j,count=0;
    scanf("%d %d %d %s",&n,&k,&p,a);
    for(i=0;i<k;i++){
        for(j=0;i+(k*j)<n;j++){
            b[count++]=a[i+(k*j)];
        }
    }
    printf("%s\n",b);
    for(i=0;i<n;i++){
        if(islower(b[i])){
            for(j=0;j<p;j++){
                b[i]++;
                if(b[i]>'z'){
                    b[i]='a';
                }
            }
        }else{
            for(j=0;j<p;j++){
                b[i]++;
                if(b[i]>'Z'){
                    b[i]='A';
                }
            }
        }
    }
    printf("%s",b);
    return 0;
}
