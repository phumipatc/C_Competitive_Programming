/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int opr,id;
};
struct B{
    int id;
    bool operator < (const B&o) const{
        return id>o.id;
    }
};
A a[10010];
B Ans;
map< int, int> mapp;
priority_queue< B> heap[21];
int cash[21][50010],tree[21][50010],compress[50010];
void update(int id,int idx,int val){
    while(idx<=50009){
        tree[id][idx]+=val;
        idx+=(idx&(-idx));
    }
}
int query(int id,int idx){
    int sum = 0;
    while(idx>0){
        sum+=tree[id][idx];
        idx-=(idx&(-idx));
    }
    return sum;
}
int main(){
    int minn,ans,n,q,num,x,id = 1,idx = 1,now;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        cash[i][0] = num;
        for(int j=1;j<=num;j++){
            scanf("%d",&x);
            cash[i][j] = x;
            compress[idx++] = x;
        }
    }
    for(int i=1;i<=q;i++){
        scanf("%d %d",&a[i].opr,&a[i].id);
        if(a[i].opr)
            compress[idx++] = a[i].id;
    }
    sort(compress+1,compress+idx);
    for(int i=1;i<idx;i++)
        mapp[compress[i]] = i;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=cash[i][0];j++){
            update(i,mapp[cash[i][j]],1);
            heap[i].push({mapp[cash[i][j]]});
        }
    }
    for(int i=1;i<=q;i++){
        if(a[i].opr){
            minn = 1e9;
            for(int j=1;j<=n;j++){
                ans = query(j,mapp[a[i].id]);
                if(minn>ans){
                    minn = ans;
                    now = j;
                }
            }
            printf("%d\n",now);
            update(now,mapp[a[i].id],1);
            heap[now].push({mapp[a[i].id]});
        }else{
            if(heap[a[i].id].empty())   continue;
            Ans = heap[a[i].id].top();
            update(a[i].id,Ans.id,-1);
            heap[a[i].id].pop();
        }
    }
    return 0;
}
/*
5 5
3 1 9 19
2 4 11
4 5 6 10 17
2 7 21
5 12 14 15 16 20
1 3
0 2
0 3
1 18
1 2
*/
