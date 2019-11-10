/*
    TASK:Again Write
    AUTHOR:Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
char a[100];
char c[100];
char k[100];
int main()
{
    int j,x,lena,lenb;
        scanf("%d",&x);
            for(j=0;j<x;j++){
                char b[42000];
                    scanf(" %s %s",a,b);
                        strcat(a,b);
                            lena=strlen(a);
                        lenb=strlen(b);
                    if(lenb>lena){
                        k[j]=strncmp(a,b,lenb);
                    }else if(lenb<lena){
                        k[j]=1;
                    }
            }
            for(j=0;j<x;j++){
                if(k[j]==0){
                    printf("Yes\n");
                }else if(k[j]==1){
                    printf("No\n");
                }
            }
return 0;
}
