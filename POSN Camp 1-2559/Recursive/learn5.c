/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
void print(int n,int x[]){
    int i;
    for(i=0;i<n;i++){
        printf("%d",x[i]);
    }
    printf("\n");
}
void permu(int n,int x[],int k){
    int i,j;
    if(k==n){
        print(n,x);
    }else{
        for(i=1;i<=n;i++){
            x[k]=i;
            j=1;
            while(j<=k && x[j-1]!=x[k])
                j++;
            if(j>k)
                permu(n,x,k+1);
        }
    }
}
int main(){
    int x[]={1,2,3,4};
    permu(4,x,0);
return 0;
}
