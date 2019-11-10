/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int k, a[3000010];
void sport(int state,int win,int lose){
    if(win == k || lose == k){
        for(int i=0;i<state;i++){
            if(a[i])    printf("W ");
            else        printf("L ");
        }
        printf("\n");
        return ;
    }
    a[state] = 1;
    sport(state+1,win+1,lose);
    a[state] = 0;
    sport(state+1,win,lose+1);
}
int main()
{
    int w,l;
    scanf("%d %d %d",&k,&w,&l);
    sport(0,w,l);
    return 0;
}
