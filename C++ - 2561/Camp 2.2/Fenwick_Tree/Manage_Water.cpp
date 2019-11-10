/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[2010][2010];
void update(int x,int y,int v){
    for(int i=x;i<=2003;i+= i & -i){
        for(int j=y;j<=2003;j+= j & -j){
            tree[i][j]+=v;
        }
    }
}
int query(int x,int y){
    int sum = 0;
    for(int i=x;i>0;i-= i & -i){
        for(int j=y;j>0;j-= j & -j){
            sum+=tree[i][j];
        }
    }
    return sum;
}
int main(){
    int opr,n,x1,x2,y1,y2,v;
    scanf("%d %d",&opr,&n);
    while(1){
        scanf("%d",&opr);
        if(opr == 3)    break;
        if(opr == 1){
            scanf("%d %d %d",&x1,&y1,&v);
            x1++,y1++;
            update(x1,y1,v);
        }else{
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            x1++,y1++,x2++,y2++;
            printf("%d\n",query(x2,y2)-query(x1-1,y2)-query(x2,y1-1)+query(x1-1,y1-1));
        }
    }
	return 0;
}
