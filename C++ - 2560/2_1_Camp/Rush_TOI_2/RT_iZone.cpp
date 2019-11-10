/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[10][1000100],color[1000100],n;
void update(int idx,int value,int c){
    while(idx<=n){
        tree[c][idx]+=value;
        idx+=(idx&-idx);
    }
}
int query(int idx,int c){
    int sum=0;
    while(idx>0){
        sum+=tree[c][idx];
        idx-=(idx&-idx);
    }
    return sum;
}
int main(){
    int m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        if(i%3==0){
            color[i]=3;
        }else{
            color[i]=i%3;
        }
        update(i,1,color[i]);
    }
    for(int i=1;i<=m;i++){
        int opr;
        scanf("%d",&opr);
        if(opr==1){
            int idx;
            char c;
            scanf("%d %c",&idx,&c);
            update(idx,-1,color[idx]);
            if(c=='R')      color[idx]=1,update(idx,1,1);
            else if(c=='G') color[idx]=2,update(idx,1,2);
            else            color[idx]=3,update(idx,1,3);
        }else if(opr==2){
            int st,en;
            scanf("%d %d",&st,&en);
            int R=query(en,1)-query(st-1,1);
            int G=query(en,2)-query(st-1,2);
            int B=query(en,3)-query(st-1,3);
            if(R>G && R>B)      printf("R\n");
            else if(G>R && G>B) printf("G\n");
            else if(B>R && B>G) printf("B\n");
            else                printf("None\n");
        }
    }
    return 0;
}
/*
10 7
1 2 R
2 1 5
1 5 B
1 3 G
2 4 8
2 1 8
2 5 6
*/
