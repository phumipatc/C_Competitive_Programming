/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int a[100100];
double b[100100];
char c[100100];
struct dd{
    char word[200];
};
typedef struct dd dd;
dd d[100100];
int cmp1(const void *a,const void *b){
    if(*(int *)a > *(int *)b){
        return 1;
    }else{
        return -1;
    }
}
int cmp2(const void *a,const void *b){
    if(*(double *)a > *(double *)b){
        return 1;
    }else{
        return -1;
    }
}
int cmp3(const void *a,const void *b){
    if(*(char *)a > *(char *)b){
        return 1;
    }else{
        return -1;
    }
}
int cmp4(const void *a,const void *b){
    dd *p,*q;
    p=(dd*)a,q=(dd*)b;
    return strcmp(p->word,q->word);
}
int main()
{
    int opr,i,n;
    scanf("%d %d",&opr,&n);
    if(opr==1){
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        qsort(a,n,sizeof(int),cmp1);
        for(i=0;i<n;i++){
            printf("%d",a[i]);
        }
        printf("\n");
        for(i=n-1;i>=0;i--){
            printf("%d",a[i]);
        }
        printf("\n");
    }else if(opr==2){
        for(i=0;i<n;i++){
            scanf("%lf",&b[i]);
        }
        qsort(b,n,sizeof(double),cmp2);
        for(i=0;i<n;i++){
            printf("%.0lf ",b[i]);
        }
        printf("\n");
        for(i=n-1;i>=0;i--){
            printf("%.0lf ",b[i]);
        }
        printf("\n");
    }else if(opr==3){
        for(i=0;i<n;i++){
            scanf(" %c",&c[i]);
        }
        qsort(c,n,sizeof(char),cmp3);
        for(i=0;i<n;i++){
            printf("%c ",c[i]);
        }
        printf("\n");
        for(i=n-1;i>=0;i--){
            printf("%c ",c[i]);
        }
        printf("\n");
    }else if(opr==4){
        for(i=0;i<n;i++){
            scanf(" %s",d[i].word);
        }
        qsort(d,n,sizeof(d[0]),cmp4);
        for(i=0;i<n;i++){
            printf("%s ",d[i].word);
        }
        printf("\n");
        for(i=n-1;i>=0;i--){
            printf("%s ",d[i].word);
        }
        printf("\n");
    }
return 0;
}
