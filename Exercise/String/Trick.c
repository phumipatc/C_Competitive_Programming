#include<stdio.h>
#include<math.h>
char a[1000],b[100];
int main()
{
   int i,j,len,m,n,sum;
        scanf(" %s",a);
        len=strlen(a);
        if(len%3==0){
            for(i=0;i<len;i+=3)
            { int aa,bb,cc;
                aa = a[i]-'0';
                aa*=4;
                bb = a[i+1]-'0';
                bb*=2;
                cc = a[i+2]-'0';
                cc*=1;
                sum=aa+bb+cc;
            printf("%d",sum);
            }
        }else if(len%3==1){
            b[0]='0';
            b[1]='0';
            for(i=0;i<len;i++)
                b[i+2]=a[i];

                int aa,bb,cc;
                for(i=0;i<len;i+=3){
                aa = b[i]-'0';
                aa*=4;
                bb = b[i+1]-'0';
                bb*=2;
                cc = b[i+2]-'0';
                cc*=1;
                sum=aa+bb+cc;
            printf("%d",sum);
                }

        }else{b[0]='0';

            for(i=0;i<len;i++)

                b[i+1]=a[i];
                int aa,bb,cc;
                for(i=0;i<len;i+=3){
                aa = b[i]-'0';
                aa*=4;
                bb = b[i+1]-'0';
                bb*=2;
                cc = b[i+2]-'0';
                cc*=1;
                sum=aa+bb+cc;
                printf("%d",sum);

        }
        }

return 0;
}
