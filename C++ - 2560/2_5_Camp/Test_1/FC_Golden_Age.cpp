/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int w[5005],n,mem[5005][5005];
int choose(int now,int k){
    if(now>n)           return 0;
    if(mem[now][k]!=-1) return mem[now][k];
    if(k == 0)          return mem[now][k] = 0;
    int maxx=-1;
    for(int i=0;i<k;i++)
        maxx=max(maxx,choose(now*2,i)+choose((now*2)+1,k-i-1));
    return mem[now][k]=maxx+w[now];
}
int main(){
    int k,maxx=-1;
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        cin >> w[i];
    memset(mem,-1,sizeof mem);
    for(int i=1;i<=n;i++)
        maxx=max(maxx,choose(i,k));
    cout << maxx << endl;
    return 0;
}
