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
            }
        }
    }
    return temp;
}
matrix ans,p[30];
int main(){
    int q;
    scanf("%d",&q);
    p[0]={{1,2,3,6,1,1,0,3,1,0,1,2,0,1,1,1}};
    for(int i=1;i<=20;i++)
        p[i]=multi(p[i-1],p[i-1]);
    while(q--){
        int n;
        scanf("%d %d %d %d %d",&a,&b,&c,&n,&x);
        ans={{a,0,0,0,0,b,0,0,0,0,c,0,0,0,0,1}};
        for(int i=0;i<=20;i++)
            if(n&(1<<i))
                ans=multi(ans,p[i]);
        for(int i=0;i<4;i++)
            printf("%d ",ans.a[i][0]%x);
        printf("\n");
    }
    return 0;
}
