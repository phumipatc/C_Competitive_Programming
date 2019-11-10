#include<stdio.h>
#include<math.h>
int main()
{
   int x,i,j,h,g;
   char a;

    scanf("%c %d",&a,&x);
    if(x%2==0){
    for(i=1;i<=x/2;i++){
       for(j=1;j<=i;j++){
        printf("%c",a);
    }
        for(h=1;h<=x-2*i;h++){
        printf(".");
    }
        for(g=1;g<=i;g++){
            printf("%c",a);
        }
    printf("\n");
    }
    for(i=(x-1)/2;i>=1;i--){
       for(j=1;j<=i;j++){
        printf("%c",a);
    }
        for(h=1;h<=x-2*i;h++){
        printf(".");
    }
        for(g=1;g<=i;g++){
            printf("%c",a);
        }
    printf("\n");
    }
    }else{
    }
return 0;
}
