/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int n,a[15];
void play(int state,int b){
    int i;
    if(state>n)
        return ;
    if(state==n){
        for(i=0;i<b;i++){
            if(a[i]==0)
                printf("--\n");
            else
                printf("||\n");
        }
        printf("E\n");
        return ;
    }
    a[b]=0;
    play(state+1,b+1);
    a[b]=1;
    play(state+2,b+1);
}
int main(){
    scanf("%d",&n);
    play(0,0);
return 0;
}
