/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
map<int,int> mapp;
int n,opr[300100],num[300100],s[300100],tree[300100];
void update(int idx,int value){
    while(idx<=n){
        tree[idx]+=value;
        idx+=(idx&(-idx));
    }
}
int query(int idx){
    int sum=0;
    while(idx>0){
        sum+=tree[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&opr[i],&num[i]),s[i]=num[i];
    sort(s+1,s+n+1);
    for(int i=1;i<=n;i++)   mapp[s[i]]=i;
    for(int i=1;i<=n;i++){
        if(opr[i]==1)   update(mapp[num[i]],1);
        else            printf("%d\n",query(mapp[num[i]]));
    }
    return 0;
}
