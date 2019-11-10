/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
#include<string.h>
char a[12000];
int main()
{
    int q,len,i,j,k,ch;
    scanf("%d",&q);
    while(q--)
    {
        scanf(" %s",a);
        len=strlen(a);
        for(i=len;i>=1;i--)
        {
            if(len%i!=0)
                continue;
            k=len/i;
            for(j=0,ch=1;j<len;j+=k)
            {
                if(strncmp(a,&a[j],k)!=0)
                {
                    ch=0;
                    break;
                }
            }
            if(ch)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}
