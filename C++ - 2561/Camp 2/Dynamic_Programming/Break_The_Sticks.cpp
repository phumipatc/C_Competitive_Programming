/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int n,dp[55][55],a[55];
int stick(int l,int r,int len,int fir){
    if(l == r)      return 0;
    if(dp[l][r])    return dp[l][r];
    int num,minn = 1e9;
    for(int i=l;i<r;i++){
        num = stick(l,i,a[i]-fir,fir)+stick(i+1,r,len-a[i]+fir,a[i])+len;
        minn = min(minn,num);
    }
    return dp[l][r] = minn;
}
int main(){
    int p;
    scanf("%d %d",&n,&p);
    for(int i=0;i<p;i++)
        scanf("%d",&a[i]);
    printf("%d\n",stick(0,p,n,0));
	return 0;
}
