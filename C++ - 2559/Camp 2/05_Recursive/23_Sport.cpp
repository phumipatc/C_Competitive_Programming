/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int n,k,q,a[1000],b[15],c[25];
void play(int state,int a1,int b){
    int i,j,i2,countt1,countt2;

       if(a1 == n || b==n){
        for(i=0;i<state;i++){
            if(a[i]==0) printf("W ");
            else        printf("L ");
        }
        printf("\n");
        return ;
    }
    a[state]=0;
    play(state+1,a1+1,b);
    a[state]=1;
    play(state+1,a1,b+1);
}
int main(){
    scanf("%d %d %d",&n,&q,&k);
    play(0,q,k);
    return 0;
    }
