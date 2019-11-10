/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
    char a[100];
}A;
A w[10100];
int cmp(const void *a,const void *b){
    A *p,*q;
    p=(A *)a;
    q=(A *)b;
    return strcmp(p->a,q->a);
}
char b[100];
int main()
{
    int n,m,k,i,p,q,mid,ch;
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<n;i++)
        scanf(" %s",w[i].a);
    qsort(w,n,sizeof(w[0]),cmp);
    for(i=0;i<m;i++){
        scanf(" %s",b);
        p=0,q=n-1,ch=1;
        while(p<=q){
            mid=(p+q)/2;
            if(!strcmp(w[mid].a,b)){
                printf("Accepted\n");
                ch=0;
                break;
            }else if(strcmp(b,w[mid].a)<0)
                q=mid-1;
            else
                p=mid+1;
        }
        if(ch==1)
            printf("Rejected");
    }
return 0;
}
