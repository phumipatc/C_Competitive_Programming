/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[1030][1030];
void update(int now,int idx,int v){
    while(idx<=1026){
        tree[now][idx]+=v;
        idx+=idx&(-idx);
    }
}
int query(int now,int idx){
    int sum = 0;
    while(idx>0){
        sum+=tree[now][idx];
        idx-=idx&(-idx);
    }
    return sum;
}
int main(){
    int n,opr,x,y,x2,y2,v,sum;
    scanf("%d %d",&opr,&n);
    while(1){
        scanf("%d",&opr);
        if(opr == 3)    break;
        if(opr == 1){
            scanf("%d %d %d",&x,&y,&v);
            update(x,y,v);
        }else{
            scanf("%d %d %d %d",&x,&y,&x2,&y2);
            sum = 0;
            for(int i=x;i<=x2;i++)
                sum+=query(i,y2)-query(i,y-1);
            printf("%d\n",sum);
        }
    }
    return 0;
}
