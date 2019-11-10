/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *a,const void*b){
    return *(int *)b-*(int *)a;
}
int main(){
    int i,j,a[100100],b,k,sum=0;
    scanf("%d",&k);
    for(i=0;i<k;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,k,sizeof(a[0]),cmp);
        for(i=0;i<k;i++){
            sum+=a[i];
        }
        for(i=1;i<k/2;i+=2){
            sum-=a[i];
        }

    printf("%d",sum);

       return 0;
}
/*
*/
