/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[200010],mark[1050000],a[200010],inv[200010];
void update(int idx,int v){
    while(idx<=200003){
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
    int n,q,countt = 1;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        mark[a[i]] = countt++;
        inv[mark[a[i]]] = a[i];
        update(mark[a[i]],1);
    }
    char opr;
    int num;
    while(q--){
        scanf(" %c %d",&opr,&num);
        if(opr == 'B'){
            update(mark[num],-1);
            mark[num] = countt++;
            inv[mark[num]] = num;
            update(mark[num],1);
        }else if(opr == 'I'){
            int l = 1,r = countt-1;
            while(l<r){
                int mid = (l+r)/2;
                // printf("%d %d %d %d\n",l,r,mid,query(mid));
                if(query(mid)>=num) r = mid;
                else                l = mid+1;
            }
            printf("%d\n",inv[l]);
        }else if(opr == 'K'){
            printf("%d\n",query(mark[num]));
        }else{
            mark[num] = countt++;
            inv[mark[num]] = num;
            update(mark[num],1);
        }
    }
	return 0;
}