/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int tree[2010][2010];
void update(int i,int j,int v){
    int temp;
    while(i<=2005){
        temp = j;
        while(temp<=2005){
            tree[i][temp]+=v;
            temp+=(temp & -temp);
        }
        i+=(i & -i);
    }
}
int query(int i,int j){
    int sum = 0,temp;
    while(i>0){
        temp = j;
        while(temp>0){
            sum+=tree[i][temp];
            temp-=(temp & -temp);
        }
        i-=(i & -i);
    }
    return sum;
}
int main(){
    int opr,n,i,j,v,k,l;
    scanf("%d %d",&opr,&n);
    while(1){
        scanf("%d",&opr);
        if(opr == 3)    break;
        if(opr == 1){
            scanf("%d %d %d",&i,&j,&v);
            i++,j++;
            update(i,j,v);
        }else{
            scanf("%d %d %d %d",&i,&j,&k,&l);
            i++,j++,k++,l++;
            printf("%d\n",query(k,l)+query(i-1,j-1)-query(k,j-1)-query(i-1,l));
        }
    }
	return 0;
}
