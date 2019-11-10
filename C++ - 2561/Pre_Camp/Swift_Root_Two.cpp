/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct matrix{
    int a[4][4];
};
int a,b,c,n,x;
matrix temp;
matrix multi(matrix A,matrix B){
    memset(temp.a,0,sizeof temp.a);
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                temp.a[i][j]+=A.a[i][k]*B.a[k][j];
                temp.a[i][j]%=x;
            }
        }
    }
    return temp;
}
matrix ans,p[35];
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int n;
        scanf("%d %d %d %d %d",&a,&b,&c,&n,&x);
        ans = {{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}};
        p[0] = {{a,2*b,3*c,0,b,a,0,3*c,c,0,a,2*b,0,c,b,a}};
        for(int i=1;i<=30;i++)
            p[i] = multi(p[i-1],p[i-1]);
        for(int i=0;i<=30;i++)
            if(n&(1<<i))
                ans = multi(ans,p[i]);
        for(int i=0;i<4;i++)
            printf("%d ",ans.a[i][0]%x);
        printf("\n");
    }
    return 0;
}
