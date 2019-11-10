/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int n,m,a[15],mark[15],ans[15];
void food(int state){
    int i;
    if(state==n){
        for(i=0;i<n;i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
        return ;
    }
    for(i=1;i<=n;i++)
        if(a[i]!=-1){
            a[i]=-1;
            ans[state]=i;
            food(state+1);
            a[i]=0;
        }
}
int main(){
    int i,num;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf("%d",&num);
        mark[num]=-1;
    }
    for(i=1;i<=n;i++){
        if(mark[i]!=-1){
            ans[0]=i;
            a[i]=-1;
            food(1);
            a[i]=0;
        }
    }
return 0;
}
