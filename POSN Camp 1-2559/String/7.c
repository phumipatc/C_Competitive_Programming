/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
char a[100];
char b[100000];
int main()
{
    int q,i,lena,lenb;
    scanf("%d",&q);
    while(q--){
        scanf(" %s %s",a,b);
        lena=strlen(a);
        lenb=strlen(b);
        if(lenb%lena!=0){
            printf("No\n");
            continue;
        }
        int ch=1;
        for(i=0;i<lenb;i+=lena){
            if(strncmp(&b[i],a,lena)!=0){
                ch=0;
                break;
            }
        }
        printf((ch)?"Yes\n":"No\n");
    }
return 0;
}
