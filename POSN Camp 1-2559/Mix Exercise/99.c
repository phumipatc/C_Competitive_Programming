/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct{
    double r;
    int cost,i;
}Q;
Q a[35000];
int cmp(const void *a,const void *b){
    Q *p=(Q*)a;
    Q *q=(Q*)b;
    if(p->r>q->r){
        return -1;
    }
    return 1;
}

int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        a[i].r=(double)x/(double)y;
        a[i].cost=y;
        a[i].i=i+1;
    }
    qsort(a,n,sizeof(a[0]),cmp);
    printf("%d\n",a[1].cost+a[0].cost+a[2].cost);
    for(i=0;i<3;i++)
        printf("%d \n",a[i].i);

            return 0;
}
/*
6
0 521
442 210
119 100
120 108
619 744
48 10
*/
