/*
    TASK: combination
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL: RYW
    LANG: C
            */
#include<stdio.h>
int count=0,k,p;
void combi(int n,int r,int arr[],int ans[],int s,int e,int index){
    int i;
    if(index==r){
            count++;
    if(count==k)
        print(r,ans);
    }else{
        for(i=s;i<=e &&e-i+1>=r-index;i++){
            ans[index] =arr[i];
            combi(n,r,arr,ans,i+1,e,index+1);
        }

        }
}
void print(int n,int x[n]){
int i;
        for(i=0;i<n;i++)
            printf("%d ",x[i]);
        printf("\n");
}
int main()
{
    int n,r,i;
    int x[100];
    int ans[500];
    scanf("%d %d %d",&n,&r,&k);
    for(i=0;i<n;i++)
        x[i]=i+1;
    combi(n,r,x,ans,0,n-1,0);
       return 0;
}
