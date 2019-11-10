/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MAX 500000
using namespace std;
vector<int> p;
int prime[500100],mem[3][500100];
int play(int player,int n){
    if(n==0)                return player;
    if(n==1)                return !player;
    if(mem[player][n]!=-1)  return mem[player][n];
    vector<int> divide;
    int sum=0,temp=n;
    for(int i=0;i<p.size();i++){
        if(temp%p[i]==0)
            divide.push_back(p[i]),sum+=p[i];
        while(temp%p[i]==0)
            temp/=p[i];
    }
    if(temp!=1) divide.push_back(temp),sum+=temp;
    int minn=1e9,maxx=-1;
    for(int i=0;i<divide.size();i++){
        if(player==1)
            maxx=max(maxx,play(0,sum-divide[i]));
        else
            minn=min(minn,play(1,sum-divide[i]));
      //  printf("%d to %d from %d\n",sum - divide[i],play(1,sum-divide[i]),n);
    }
    if(player==1)   return mem[player][n]=maxx;
    else            return mem[player][n]=minn;
}
int main(){
    int q;
    p.push_back(2);
    for(int i=3;i<=sqrt(MAX);i+=2)
    {
        if(prime[i])    continue;
        p.push_back(i);
        for(int j=i*i;j<=MAX;j+=i)
            prime[j] = 1;
    }
    memset(mem,-1,sizeof mem);
    scanf("%d",&q);
    while(q--){
        int n;
        scanf("%d",&n);
        printf("%d\n",play(1,n) ? 1:2);
    }
    return 0;
}
//497655
