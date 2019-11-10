/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y;
};
A a[12];
int dp[12][12],cut[12][12];
int chain(int l,int r){
    if(l == r)  return 0;
    int sum,minn = 1e9;
    for(int i=l;i<r;i++){
        sum = chain(l,i)+chain(i+1,r)+(a[l].x*a[i].y*a[r].y);
        if(sum<minn){
            minn = sum;
            cut[l][r] = i;
        }
    }
    return dp[l][r] = minn;
}
void print(int l,int r){
    if(l == r){
        printf("A%d",l);
        return ;
    }
    printf("(");
    print(l,cut[l][r]);
    printf(" x ");
    print(cut[l][r]+1,r);
    printf(")");
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i].x,&a[i].y);
    printf("%d\n",chain(1,n));
    print(1,n);
	return 0;
}
