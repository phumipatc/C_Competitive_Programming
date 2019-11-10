#include<stdio.h>
int main()
{
    int n,i,j;
    char a;
    scanf("%c %d",&a,&n);
    for(i=0;i<n/2;i++){
        for(j=0;j<=i;j++){
            printf("%c",a);
        }
        for(j=0;j<(n/2)-1-i;j++){
            printf("..");
        }
        for(j=0;j<=i;j++){
            printf("%c",a);
        }
        printf("\n");
    }
    for(i=0;i<n/2-1;i++){
        for(j=0;j<n/2-i-1;j++){
            printf("%c",a);
        }
        for(j=0;j<=i;j++){
            printf("..");
        }
        for(j=0;j<n/2-i-1;j++){
            printf("%c",a);
        }
        printf("\n");
    }
    return 0;
}
