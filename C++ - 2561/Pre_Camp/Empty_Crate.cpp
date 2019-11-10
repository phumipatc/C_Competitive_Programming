/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[20010],tree[1010],mark[1010];
void update(int idx,int v){
    while(idx<=1000){
        tree[idx]+=v;
        idx+= idx & -idx;
    }
}
int query(int idx){
    int sum = 0;
    while(idx>0){
        sum+=tree[idx];
        idx-= idx & -idx;
    }
    return sum;
}
int main(){
    int m,n,st,en,ch = 1,countt,ans;
    scanf("%d %d",&m,&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    st = en = 1;
    for(int i=1;i<=n/2;i++){
        mark[a[i]]++,ch = 1,countt = 0;
        while(st<=i)    update(a[st],-1),st++;
        while(en<=2*i)  update(a[en],1),en++;
        for(int j=m;j>=1;j--){
            if(!mark[j])    continue;
            countt+=mark[j];
            // printf("%d %d %d %d\n",i,j,countt,query(1000)-query(j));
            if(query(1000)-query(j)<countt) ch = 0;
        }
        if(ch)  ans = i;
    }
    printf("%d\n",ans);
	return 0;
}
