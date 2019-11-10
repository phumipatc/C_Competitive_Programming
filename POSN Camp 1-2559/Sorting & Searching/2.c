#include <stdio.h>
#include <stdlib.h>
typedef struct A{
    int x,y;
}aa;
aa a[100100];
int cmp(const void* a,const void* b){
  aa *p,*q;
  p=(aa *)a,q=(aa *)b;
  if(p->x==q->x){
    return q->y - p->y;
  }
  return p->x - q->x;
}
int main(){
 int n,i;
 scanf("%d",&n);
 for(i=0;i<n;i++)
    scanf("%d %d",&a[i].x,&a[i].y);
 qsort(a,n,sizeof(a[0]),cmp);
 for(i=0;i<n;i++)
    printf("%d %d\n",a[i].x,a[i].y);

return 0;
}
