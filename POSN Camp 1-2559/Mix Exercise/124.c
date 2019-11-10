/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int a[1010]={1};
int main(){
    int n,m,len=1,i,j,tod=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++){
        tod=0;
        for(j=0;j<len;j++){
            a[j]=a[j]*n+tod;
            tod=(a[j]/10);
            a[j]%=10;

        }
        if(tod){
            a[j]=tod;
        }
        if(a[len]!=0)
            len++;
    }
    for(i=len-1;i>=0;i--){
        printf("%d",a[i]);
    }
    return 0;
}
