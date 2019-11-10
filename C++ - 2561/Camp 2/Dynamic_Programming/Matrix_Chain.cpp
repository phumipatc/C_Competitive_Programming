/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int r,c,id;
};
A a[12];
int dp[12][12],cut[12][12];
int matrix_mul(int l,int r){
    if(l == r)      return 0;
    if(dp[l][r])    return dp[l][r];
    int num,minn = 1e9;
    for(int i=l;i<r;i++){
        num = matrix_mul(l,i)+matrix_mul(i+1,r)+(a[l].r*a[i].c*a[r].c);
        if(num<minn){
            minn = num;
            cut[l][r] = i;
        }
    }
    return dp[l][r] = minn;
}
void print(int l,int r){
    if(l == r){
        printf("A%d",a[l].id);
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
        scanf("%d %d",&a[i].r,&a[i].c),a[i].id = i;
    printf("%d\n",matrix_mul(1,n));
    print(1,n);
	return 0;
}
