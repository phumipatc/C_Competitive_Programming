/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int score;
char ans[3000010];
void play(int state,int win,int lose){
    int i;
    if(win==score || lose==score){
        for(i=0;i<state;i++){
            printf("%c ",ans[i]);
        }
        printf("\n");
        return ;
    }
    ans[state]='W';
    play(state+1,win+1,lose);
    ans[state]='L';
    play(state+1,win,lose+1);
}
int main(){
    int win,lose;
    scanf("%d %d %d",&score,&win,&lose);
    play(0,win,lose);
return 0;
}
