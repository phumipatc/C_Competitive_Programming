/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
char a[100100],b[100100];
int main()
{
    int i,len,q,x,y,ch=0;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",a);
        len=strlen(a);
        for(i=0;i<len;i++)
            b[len-i-1]=a[i];
        b[len]='\0';
        x=0,y=0;
        for(i=0;i<len;){
            if(strncmp("zzZzZ",&b[i],5)==0)
                x++,i+=5;
            else if(strncmp(&b[i],"ZzzzZ",5)==0)
                x--,i+=5;
            else if(strncmp(&b[i],"zzzZ",4)==0)
                y++,i+=4;
            else if(strncmp(&b[i],"zZZz",4)==0)
                y--,i+=4;
            else{
                ch=1;  break;
            }
        }
        if(ch||i!=len)
            printf("It isn't Peatty's snore.\n");
        else
            printf("%.2lf\n",sqrt((double)x*x+y*y));
    }
return 0;
}
