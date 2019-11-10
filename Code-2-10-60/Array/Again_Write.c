/*
    Task :
    Author : Boss
    School : RYW
    Language : C
*/
#include<stdio.h>
#include<string.h>
char a[50],b[42000];
int main()
{
    int i,j,q,lena,lenb,k=0;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",a);
        scanf(" %s",b);
        lena=strlen(a);
        lenb=strlen(b);
        if(lenb%lena!=0){
            printf("No\n");
            continue;
        }
        for(i=0;i<lenb;i++){
            if(b[i]!=a[i%lena]){
                k=1;
                break;
            }
            k=0;
        }
        if(k==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
