/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int sed,suan;
    double val;
}A;
A a[30000];
int gcd(int a,int b){
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}
int cmp(const void* a,const void* b){
    A *p,*q;
    p=(A *)a,q=(A *)b;
    if(p->val > q->val) return 1;
    else return -1;
}
int main()
{
    int n,i,j,count=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<i;j++){
            if(gcd(i,j)==1){
                a[count].sed=j, a[count].suan=i;
                a[count].val=(double)j/i;
                count++;
            }
        }
    }
    qsort(a,count,sizeof(a[0]),cmp);
    printf("0/1\n");
    for(i=0;i<count;i++)
        printf("%d/%d\n",a[i].sed,a[i].suan);
    printf("1/1\n");
    return 0;
}
