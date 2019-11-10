/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
char a[1000];
char b[100];
int main()
{
    /*
    int len,sum,i;
    scanf("%s",a);
    len=strlen(a);
    if(len%3==0){
            for(i=0;i<len;i+=3){
                int x,y,z;
                x = a[i]-'0';
                x*=4;
                y = a[i+1]-'0';
                y*=2;
                z = a[i+2]-'0';
                z*=1;
                sum=x+y+z;
            printf("%d",sum);
            }
        }else if(len%3==1){
            b[0]='0';
            b[1]='0';
            for(i=0;i<len;i++){
                b[i+2]=a[i];
            }
                int x,y,z;
                for(i=0;i<len;i+=3){
                x = b[i]-'0';
                x*=4;
                y = b[i+1]-'0';
                y*=2;
                z = b[i+2]-'0';
                z*=1;
                sum=x+y+z;
            printf("%d",sum);
                }

        }else{b[0]='0';

            for(i=0;i<len;i++)

                b[i+1]=a[i];
                int x,y,z;
                for(i=0;i<len;i+=3){
                x = b[i]-'0';
                x*=4;
                y = b[i+1]-'0';
                y*=2;
                z = b[i+2]-'0';
                z*=1;
                sum=x+y+z;
                printf("%d",sum);
        }
        }
        */
        int len,i;
        scanf(" %s",a);
        len=strlen(a);
        memset(b,'0',sizeof b);
        if(len%3==0)        strcpy(b,a);
        else if(len%3==1)   strcpy(&b[2],&a[0]);
        else if(len%3==2)   strcpy(&b[1],a
                                   );
        len=strlen(b);
        for(i=0;i<len;i+=3){
            if(strncmp(&b[i],"000",3)==0)
                printf("0");
            if(strncmp(&b[i],"001",3)==0)
                printf("1");
            if(strncmp(&b[i],"010",3)==0)
                printf("2");
            if(strncmp(&b[i],"011",3)==0)
                printf("3");
            if(strncmp(&b[i],"100",3)==0)
                printf("4");
            if(strncmp(&b[i],"101",3)==0)
                printf("5");
            if(strncmp(&b[i],"110",3)==0)
                printf("6");
            if(strncmp(&b[i],"111",3)==0)
                printf("7");
        }
return 0;
}
