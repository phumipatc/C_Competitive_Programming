/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int h[300100],l[300100],r[300100];
char warp[300100];
int main(){
    int n,k,i,t=0,maxx=-1;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)   scanf("%d",&h[i]);
    scanf(" %s",warp+1);
    for(i=2;i<=n;i++){
        if(h[i]<h[i-1]) continue;
        if(warp[i-1]=='T')  warp[i]='T';
        l[i]=l[i-1]+1;
    }
    for(i=n-1;i>0;i--){
        if(h[i]<h[i+1]) continue;
        if(warp[i+1]=='T')  warp[i]='T';
        r[i]=r[i+1]+1;
    }
    for(i=1;i<=n;i++){
        if(warp[i]=='T')
            t++;
        else
            maxx=max(maxx,max(l[i],r[i])+1);
    }
    if(warp[k]=='T'){
        printf("%d\n",t+maxx);
    }else{
        int common_left,common_right;
        common_left=common_right=k;
        while(common_left>1 && h[common_left-1]==h[k])      common_left--;
        while(common_right<n && h[common_right+1]==h[k])    common_right++;
        printf("%d\n",(common_right-common_left+1)+max(l[common_left],r[common_right]));
    }
    return 0;
}
