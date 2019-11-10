/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<stdio.h>
int s,n,count,a[30];
void func(int sum,int state){
    int i;
    if(sum>s)
       return ;
    if(sum==s){
        count++;
        if(count==n){
            for(i=0;i<state;i++)
                printf("%d",a[i]);
        }
    }
    for(i=1;i<=9;i++){
        a[state]=i;
        func(sum+i,state+1);
    }
}
int main(){
    scanf("%d %d",&s,&n);
    count=0;
    func(0,0);
return 0;
}
