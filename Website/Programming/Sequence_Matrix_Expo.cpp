/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 2553
using namespace std;
struct A{
    int a[4][4];
    A operator * (const A&o) const{
        A temp;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                temp.a[i][j] = 0;
                for(int k=0;k<4;k++)
                    temp.a[i][j]+=a[i][k]*o.a[k][j],temp.a[i][j]%=MOD;
            }
        }
        return temp;
    }
};
A p[62],ans,temp;
int main(){
    for(int i=0;i<4;i++)
        scanf("%d",&ans.a[4-i-1][0]);
    for(int i=1;i<4;i++)
        p[0].a[i][i-1] = 1;
    for(int i=0;i<4;i++)
        scanf("%d",&p[0].a[0][i]);
    for(int i=1;i<60;i++)
        p[i] = p[i-1]*p[i-1];
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            temp.a[i][j] = ans.a[i][j];
    int q;
    long long n;
    scanf("%d",&q);
    while(q--){
        scanf("%lld",&n);
        if(n<=4){
            printf("%d\n",ans.a[4-n][0]);
            continue;
        }
        n-=4;
        for(int i=0;i<60;i++)
            if(n & (1ll<<i))
                ans = p[i]*ans;
        printf("%d\n",ans.a[0][0]);
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                ans.a[i][j] = temp.a[i][j];
    }
	return 0;
}