/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<stdlib.h>
int a[100100];
int cmp(const void *a,const void *b){
    if(*(int *)a > *(int *)b)
        return 1;
    return -1;
}
int main()
{
    int n,i,p,q,mid,Q,key,ch;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    scanf("%d",&Q);
    while(Q--){
        scanf("%d",&key);
        p=0;q=n-1,ch=1;
        while(p<=q){
            mid = (p+q)/2;
            if(a[mid]==key){
                printf("Yes\n");
                ch=0;
                break;
            }else if(key>a[mid]){
                p=mid+1;
            }else
            q=mid-1;
        }
        if(ch)
            printf("No\n");
    }
return 0;
}
