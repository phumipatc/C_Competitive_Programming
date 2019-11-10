/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int pos,val;
    bool operator < (const A&o) const{
        if(pos!=o.pos)  return pos<o.pos;
        else            return val<o.val;
    }
};
A line[200001];
int a[100001],minn[100001],maxx[100001];
int main(){
    int q,n,idx,sum,countt,ans,amount;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=100000;i++)
            minn[i] = 1e9,maxx[i] = -1;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            minn[a[i]] = min(minn[a[i]],i);
            maxx[a[i]] = max(maxx[a[i]],i);
        }
        idx = 1;
        for(int i=1;i<=100000;i++){
            if(minn[i] == 1e9 && maxx[i] == -1)    continue;
            line[idx].pos = minn[i],line[idx++].val = 1;
            line[idx].pos = maxx[i]+1,line[idx++].val = -1;
        }
        sort(line+1,line+idx);
        sum = amount = ans = countt = 0;
        for(int i=1;i<idx;i++){
            sum+=line[i].val;
            if(sum!=0)
                amount+=line[i+1].pos-line[i].pos;
            else
                countt++,ans = max(amount,ans),amount = 0;
        }
        printf("%d %d\n",ans,countt);
    }
    return 0;
}
