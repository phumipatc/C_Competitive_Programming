/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int taep[3000300],minn[3000300],tpow[50],ans[3000300];
void play(int l,int r,int i,int v,int f){
    if(l==r){
        ans[l]=v;
        return ;
    }
    int mid=(l+r)/2;
    if(taep[i]==1){
        play(l,mid,i*2,v,f+1);
        play(mid+1,r,i*2+1,v+tpow[f],f+1);
    }else{
        play(l,mid,i*2,v+tpow[f],f+1);
        play(mid+1,r,i*2+1,v,f+1);
    }
}
void play2(int l,int r,int head){
    if(r-l==1){
        if(taep[l]>taep[r]){
            ans[head]=2;
            minn[head]=taep[r];
        }else{
            ans[head]=1;
            minn[head]=taep[l];
        }
        return ;
    }
    int mid=(l+r)/2;
    play2(l,mid,head*2);
    play2(mid+1,r,head*2+1);
    if(minn[head*2]<minn[head*2+1]){
        ans[head]=1;
        minn[head]=minn[head*2];
    }else{
        ans[head]=2;
        minn[head]=minn[head*2+1];
    }
}
int main()
{
    int i,cmd,n;
    char a;
    tpow[0]=1;
    for(i=1;i<=25;i++) tpow[i]=tpow[i-1]*2;
    scanf("%d",&cmd);
    if(cmd==1){
        scanf(" %d",&n);
        for(i=1;i<tpow[n];i++){
            scanf(" %c",&a);
            if(a=='L') taep[i]=1;
            else taep[i]=2;
        }
        play(1,tpow[n],1,1,0);
        if(tpow[n]>555555) tpow[n]=555555;
        for(i=1;i<=tpow[n];i++) printf("%d ",ans[i]);
    }else{
        scanf(" %d",&n);
        for(i=1;i<=tpow[n];i++){
            scanf(" %d",&taep[i]);
        }
        play2(1,tpow[n],1);
        for(i=1;i<tpow[n];i++) printf("%c",(ans[i]==1)?'L':'R');
    }
    return 0;
}
