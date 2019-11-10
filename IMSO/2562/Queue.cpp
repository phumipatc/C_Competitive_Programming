/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[100010],id[100010],id2[200010];
void update(int idx,int v){
    while(idx<=100003){
        tree[idx]+=v;
        idx+=idx & -idx;
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
    int n,opr,num,now = 1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&opr);
        if(opr == 1){
            scanf("%d",&num);
            id[num] = now;
            id2[now++] = num;
            update(num,1);
        }else if(opr == 2){
            int l = 1,r = 100001,mid;
            while(l<r){
                mid = (l+r)/2;
                if(query(mid)>=1)   r = mid;
                else                l = mid+1;
            }
            printf("%d\n",id[l]);
            if(l!=100001)   update(l,-1);
        }else{
            scanf("%d",&num);
            printf("%d\n",query(id2[num]-1));
        }
    }
	return 0;
}