/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 100003
using namespace std;
int mem[5][110][110][110];
int top_down(int a,int b,int c,int last){
//    printf("%d %d %d\n",a,b,c);
    if(a==1 && b==0 && c==0 && last!=1) return 1;
    if(a==0 && b==1 && c==0 && last!=2) return 1;
    if(a==0 && b==0 && c==1 && last!=3) return 1;
    if(mem[last][a][b][c]!=-1)          return mem[last][a][b][c];
    int sum=0;
    if(last==1){
        if(b>0) sum+=top_down(a,b-1,c,2);
        if(c>0) sum+=top_down(a,b,c-1,3);
    }
    if(last==2){
        if(a>0) sum+=top_down(a-1,b,c,1);
        if(c>0) sum+=top_down(a,b,c-1,3);
    }
    if(last==3){
        if(a>0) sum+=top_down(a-1,b,c,1);
        if(b>0) sum+=top_down(a,b-1,c,2);
    }
    return mem[last][a][b][c]=sum%MOD;
}
int main(){
    int q,a,b,c,ans;
    scanf("%d",&q);
    while(q--){
        ans=0;
        memset(mem,-1,sizeof mem);
        scanf("%d %d %d",&a,&b,&c);
        ans+=top_down(a-1,b,c,1);
//        printf("%d\n",ans);
//        return 0;
        ans+=top_down(a,b-1,c,2);
//        printf("%d\n",ans);
//        return 0;
        ans+=top_down(a,b,c-1,3);
        if(a==1 && b==0 && c==0)    ans=1;
        if(a==0 && b==1 && c==0)    ans=1;
        if(a==0 && b==0 && c==1)    ans=1;
        printf("%d\n",ans%MOD);
    }
    return 0;
}
