/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
char str[20];
int win,lose,mem[3][2100][2100];
int stress_free(int a,int b){
    if(a<0 || b<0)          return 0;
    if(a==0 && b==0)        return mem[1][a][b]=1;
    if(a<=b)                return mem[1][a][b]=0;
    if(mem[1][a][b]!=-1)    return mem[1][a][b];
    return mem[1][a][b]=(stress_free(a-1,b)+stress_free(a,b-1))%MOD;
}
int stress_full(int a,int b){
    if(a<0 || b<0)       return 0;
    if(a==0 && b==0)     return mem[2][a][b]=1;
    if(a>b && b!=lose)   return mem[2][a][b]=0;
    if(mem[2][a][b]!=-1) return mem[2][a][b];
    return mem[2][a][b]=(stress_full(a-1,b)+stress_full(a,b-1))%MOD;
}
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        memset(mem,-1,sizeof mem);
        scanf("%d-%d",&win,&lose);
        printf("%d %d\n",stress_free(win,lose),stress_full(win,lose));
//        printf("%d %d\n",win,lose);
    }
    return 0;
}
