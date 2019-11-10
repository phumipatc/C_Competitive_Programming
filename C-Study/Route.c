/*
    TASK: Route
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL: RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    int x,y,A,B;
    scanf("%d %d %d %d",&x,&y,&A,&B);
    if(A==0)
        printf("0");
    else if(B==0)
        printf("0");
    else
        if(2*A<=B)
            printf("%d",A*x+A*y);
        else if(2*A>B)
            if(x==y)
                printf("%d",B*x);
            else if(x<y)
                if((y-x)%2==1)
                    if(A>=B)
                        printf("%d",B*(y-1)+A);
                    else
                        printf("%d",B*x+A*(y-x));
                else
                    if(A>=B)
                        printf("%d",B*y);
                    else
                        printf("%d",B*x+A*(y-x));
            else
                if((x-y)%2==1)
                    if(A>=B)
                        printf("%d",B*(x-1)+A);
                    else
                        printf("%d",B*y+A*(x-y));
                else
                    if(A>=B)
                        printf("%d",B*x);
                    else
                        printf("%d",B*y+A*(x-y));
       return 0;
}
