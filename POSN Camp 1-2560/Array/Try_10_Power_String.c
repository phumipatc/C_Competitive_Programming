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
    int q,i,len,power,j,ch,max;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",a);
        len=strlen(a);
        ch=0,max=1;
        for(i=len-1;i>0;i--){
            if(len%i!=0)    continue;
            power=len/i;
            for(j=0;j<len;j+=i){
                if(strncmp(&a[0],&a[j],i)){
                    ch=1;   break;
                }
                ch=0;
            }
            if(!ch){
                if(power>max)
                    max=power;
            }
        }
        printf("%d",max);
    }
    return 0;
}
