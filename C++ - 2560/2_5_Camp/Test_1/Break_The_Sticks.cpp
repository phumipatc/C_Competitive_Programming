/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mem[55][55],a[55];
int stick(int st,int en,int len,int First){
    if(mem[st][en])                 return mem[st][en];
    if(st == en)                            return 0;
    int minn=1e9;
    for(int i = st; i < en ;i++)
    {
        int newlen = a[i] - First;
        minn = min(minn, stick(st,i,newlen,First) + stick(i+1,en,len - newlen,a[i]) + len);
    }
    return mem[st][en] = minn;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<k;i++)
        scanf("%d",&a[i]);
    //memset(mem,-1,sizeof mem);
    printf("%d\n",stick(0,k,n,0));
    return 0;
}
