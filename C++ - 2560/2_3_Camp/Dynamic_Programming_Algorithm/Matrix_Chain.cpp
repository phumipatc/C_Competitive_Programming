/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int row[15],column[15],mic[15][15],divide[15][15];
int matrix_chain(int l,int r){
    if(mic[l][r]!=-1)   return mic[l][r];
    if(l==r)            return 0;
    int minn=1e9,k,now;
    for(int k=l;k<r;k++){
        now=matrix_chain(l,k)+matrix_chain(k+1,r)+(row[l]*column[k]*column[r]);
        if(now<minn){
            minn=now;
            divide[l][r]=k;
        }
    }
    return mic[l][r]=minn;
}
void print(int l,int r){
    if(l==r){
        printf("A%d",l);
        return ;
    }
    printf("(");
    print(l,divide[l][r]);
    printf(" x ");
    print(divide[l][r]+1,r);
    printf(")");
}
int main(){
    int n;
    scanf("%d",&n);
    memset(mic,-1,sizeof mic);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&row[i],&column[i]);
    printf("%d\n",matrix_chain(1,n));
    print(1,n);
    return 0;
}
