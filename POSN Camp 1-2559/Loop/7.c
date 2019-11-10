/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL: RYW
    LANG: C
            */
#include<stdio.h>
#include<math.h>
int main()
{
int a,b,c,d,x=0,a1,b1,c1,d1,i=1;
    scanf("%d %d %d %d",&a,&b,&c,&d);

        printf("%d %d %d %d\n",a,b,c,d);
            while(a!=0||b!=0||c!=0||d!=0){



                        a1=a;b1=b;c1=c;d1=d;
                        a=abs(a1-b1);
                        b=abs(b1-c1);
                        c=abs(c1-d1);
                        d=abs(d1-a1);
                            printf("%d %d %d %d",a,b,c,d);

                    printf("\n");

                    x++;
            }
            printf("%d",x);







       return 0;
}
