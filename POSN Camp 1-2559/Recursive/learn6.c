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
void combi(int n,int r,int arr[],int ans[],int s,int e,int index){
    int i;
    if(index==r){
        print(r,ans);
    }else{
        for(i=s;i<=e && e-i+1>=r-index;i++){
            ans[index]=arr[i];
            combi(n,r,arr,ans,i+1,e,index+1);
        }
    }
}
int main()
{
    int x[]={1,2,3,4};
    int n=4;
    int r=3;
    int ans[r];
    combi(n,r,x,ans,0,n-1,0);
return 0;
}
