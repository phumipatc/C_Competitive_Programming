/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
#include<string.h>
char a[600],*b;
int main()
{
    int q,i,len,ch;
    gets(a);
    sscanf(a,"%d",&q);
    while(q--)
    {
        gets(a);
        len=strlen(a);
        if(a[len-1]=='\r')
            a[len-1]='\0';
        b=strtok(a," ");
        ch=0;
        while(b!=NULL)
        {
            len=strlen(b);
            if(len%4==0)
            {
                for(i=0;i<len;i+=4)
                {
                    if(strncmp(&b[i],"meow",4))
                        break;
                }
                if(i==len)
                {
                    ch=1;
                    break;
                }
            }
            b=strtok(NULL," ");
        }
        printf((ch)?"YES\n":"NO\n");
    }
    return 0;
}
