/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[210],b[210],c[210],n,mem[3][210][210][210];
int pick(int idx1,int idx2,int idx3,int round){
    if(idx1==0 && idx2==0 && idx3==0)      return 0;
    if(mem[round][idx1][idx2][idx3])       return mem[round][idx1][idx2][idx3];
    if(round==1){
        int maxx=-1;
        if(idx1-1>=0)
            maxx=max(maxx,pick(idx1-1,idx2,idx3,round^1)+a[idx1]);
        if(idx2-1>=0)
            maxx=max(maxx,pick(idx1,idx2-1,idx3,round^1)+b[idx2]);
        if(idx3-1>=0)
            maxx=max(maxx,pick(idx1,idx2,idx3-1,round^1)+c[idx3]);
        //printf("1: %d\n",maxx);
        return mem[round][idx1][idx2][idx3]=maxx;
    }
    else{
        int minn=1<<30;
        if(idx1-1>=0)
            minn=min(minn,pick(idx1-1,idx2,idx3,round^1));
        if(idx2-1>=0)
            minn=min(minn,pick(idx1,idx2-1,idx3,round^1));
        if(idx3-1>=0)
            minn=min(minn,pick(idx1,idx2,idx3-1,round^1));
        //printf("2: %d\n",minn);
        return mem[round][idx1][idx2][idx3]=minn;
    }
}
int main(){
    int i,ans1,ans2,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]),sum+=a[i];
    for(i=1;i<=n;i++)
        scanf("%d",&b[i]),sum+=b[i];
    for(i=1;i<=n;i++)
        scanf("%d",&c[i]),sum+=c[i];
    ans1=pick(n,n,n,1);
    ans2=sum-ans1;
    printf("%d %d\n",ans1,ans2);
    return 0;
}
