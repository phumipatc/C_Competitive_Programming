/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[3][1000010],a[1000010];
void update(int idx,int tr,int v){
    while(idx<=1000003){
        tree[tr][idx]+=v;
        idx+= idx & -idx;
    }
}
int query(int idx,int tr){
    int sum = 0;
    while(idx>0){
        sum+=tree[tr][idx];
        idx-= idx & -idx;
    }
    return sum;
}
int main(){
    int n,m,opr,st,en,R,G,B;
    char temp;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        update(i+1,i%3,1);
        if(i%3 == 0)        a[i+1] = 0;
        else if(i%3 == 1)   a[i+1] = 1;
        else                a[i+1] = 2;
    }
    while(m--){
        scanf("%d",&opr);
        if(opr == 1){
            scanf("%d %c",&st,&temp);
            update(st,a[st],-1);
            if(temp == 'R')         a[st] = 0;
            else if(temp == 'G')    a[st] = 1;
            else                    a[st] = 2;
            update(st,a[st],1);
        }else{
            scanf("%d %d",&st,&en);
            R = query(en,0)-query(st-1,0);
            G = query(en,1)-query(st-1,1);
            B = query(en,2)-query(st-1,2);
            if(R>G && R>B)      printf("R\n");
            else if(G>R && G>B) printf("G\n");
            else if(B>R && B>G) printf("B\n");
            else                printf("None\n");
        }
    }
	return 0;
}
