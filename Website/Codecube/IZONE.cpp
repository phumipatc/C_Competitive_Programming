/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[3][1000010],col[1000010];
void update(int now,int idx,int v){
    while(idx<=1000003){
        tree[now][idx]+=v;
        idx+=idx & -idx;
    }
}
int query(int now,int idx){
    int sum = 0;
    while(idx>0){
        sum+=tree[now][idx];        
        idx-=idx & -idx;
    }
    return sum;
}
int main(){
    int n,m,opr,u,v;
    char c;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        update(i%3,i,1);
        col[i] = i%3;
    }
    while(m--){
        scanf("%d",&opr);
        if(opr == 1){
            scanf("%d %c",&u,&c);
            if(c == 'R')        v = 1;
            else if(c == 'G')   v = 2;
            else                v = 0;
            update(col[u],u,-1);
            update(v,u,1);
            col[u] = v;
        }else{
            scanf("%d %d",&u,&v);
            int r = query(1,v)-query(1,u-1);
            int g = query(2,v)-query(2,u-1);
            int b = query(0,v)-query(0,u-1);
            if(r>g && r>b)      printf("R\n");
            else if(g>r && g>b) printf("G\n");
            else if(b>r && b>g) printf("B\n");
            else                printf("None\n");
        }
    }
	return 0;
}