#include<stdio.h>
#include<math.h>
#include<string.h>
char a[50];
int main()
{
    int i,j,len,sum;
    for(i=0;i<5;i++){
            sum=0;
        scanf(" %s",a);
        len=strlen(a);
        for(j=0;j<len;j++){
            sum+=pow(a[j]-'0',j+1);

        }
        if(sum==atoi(a))
            printf("Y");
        else
            printf("N");

    }
       return 0;
}
