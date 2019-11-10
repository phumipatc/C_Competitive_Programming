/*
    TASK :
    AUTHOR : Phumipat C.
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int a[10000001];
int main()
{
    int n,i,j,count;
    scanf("%d",&n);
    if(n==1){
        printf("2\n");
        return 0;
    }
    for(i=3;i<10000000;i+=2){
        a[i]=1;
    }
    for(i=3;i<sqrt(10000000);i+=2){
        if(a[i]){
            for(j=i*i;j<10000000;j+=i){
                if(a[j]){
                    a[j]=0;
                }
            }
        }
    }
    for(i=3,count=1;count<=n;i+=2){
        if(a[i]){
            count++;
        }
        if(count==n){
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}
