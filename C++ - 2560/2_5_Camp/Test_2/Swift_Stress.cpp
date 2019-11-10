/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int mem[2005][2005][3],a,b;
int free(int win,int lose){
    if(win<0 || lose<0)         return 0;
    if(win == 0 && lose == 0)   return mem[win][lose][0] = 1;
    if(win<=lose)               return mem[win][lose][0] = 0;
    if(mem[win][lose][0]!=-1)   return mem[win][lose][0];
    return mem[win][lose][0] = (free(win-1,lose)+free(win,lose-1))%MOD;
}
int ful(int win,int lose){
    if(win<0 || lose<0)         return 0;
    if(win == 0 && lose == 0)   return mem[win][lose][1] = 1;
    if(win>lose && lose!=b)     return mem[win][lose][1] = 0;
    if(mem[win][lose][1]!=-1)   return mem[win][lose][1];
    return mem[win][lose][1] = (ful(win-1,lose)+ful(win,lose-1))%MOD;
}
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        memset(mem,-1,sizeof mem);
        scanf("%d-%d",&a,&b);
        printf("%d %d\n",free(a,b),ful(a,b));
    }
    return 0;
}
