#include<stdio.h>
#include<string.h>
char a[50],b[42000];
int main()
{
    int q;
    scanf("%d",&q);
    while(q--){
        int lena,lenb;
        scanf(" %s %s",a,b);
        lena=strlen(a);
        lenb=strlen(b);
        if(lenb%lena){
            printf("No\n");
            continue;
        }
        int i,ch=1;
        for(i=0;i<lenb;i+=lena){
            if(strncmp(&b[i],a,lena)){
                ch=0;
                break;
            }
        }
        if(ch)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
