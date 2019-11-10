/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
#include<string.h>
char a[1200],b[1200];
int main()
{
    int i,len,k,j,ch;
    scanf(" %s",a);
    len=strlen(a);
    for(i=0;i<len;i++){
        switch(a[i]){
            case 'A' : b[i]='T';  break;
            case 'T' : b[i]='A';  break;
            case 'C' : b[i]='G';  break;
            case 'G' : b[i]='C';  break;
        }
    }
    for(i=len;i>=1;i--)
        {
            for(j=0,ch=1;j<len;j+=i)
            {
                if(strncmp(a,&a[j],i)!=0)
                {
                    ch=0;
                    break;
                }
            }
            if(ch)
            {
                printf("%d\n",i);
            }
        }
    return 0;
}
