/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int n,tree[100100],pos[100100];
void update(int idx,int value){
    while(idx<=n){
        tree[idx]+=value;
        idx+=(idx&-idx);
    }
}
int query(int idx){
    int sum=0;
    while(idx>0){
        sum+=tree[idx];
        idx-=(idx&-idx);
    }
    return sum;
}
int main(){
    int num,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        pos[num]=i;
        update(i,1);
    }
    int l=1,r=n,turn=0;
    while(l<=r){
        if(turn==0){
            int ans=query(pos[l]-1);
            update(pos[l],-1);
            printf("%d\n",ans);
            turn=1;
            l++;
        }else{
            int ans=query(n)-query(pos[r]);
            update(pos[r],-1);
            printf("%d\n",ans);
            turn=0;
            r--;
        }
    }
    return 0;
}
