/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int n,a[20];
void dominoes(int state,int now){
    int i;
    if(state>n)
        return ;
    if(state==n){
        for(i=0;i<now;i++){
            if(a[i]){
                printf("--\n");
            }else{
                printf("||\n");
            }
        }
        printf("E\n");
    }
    a[now]=1;
    dominoes(state+1,now+1);
    a[now]=0;
    dominoes(state+2,now+1);
}
int main(){
    scanf("%d",&n);
    dominoes(0,0);
return 0;
}
