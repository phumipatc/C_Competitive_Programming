/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long LL;
struct A{
    LL a[3][3];
};
A p[62],ans,temp;
void mul(A *a,A *b){
    memset(temp.a,0,sizeof temp.a);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                temp.a[i][j]+=(a->a[i][k])*(b->a[k][j]);
                temp.a[i][j]%=MOD;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    LL q,n;
    p[0] = {1,1,1,1,0,0,0,1,0};
    for(int i=1;i<62;i++){
        mul(&p[i-1],&p[i-1]);
        p[i] = temp;
    }
    cin >> q;
    while(q--){
        cin >> n;
        ans = {1,0,0,0,0,0,0,0,0};
        for(int i=0;i<62;i++){
            if(n&(1ll<<i)){
                mul(&p[i],&ans);
                ans = temp;
            }
        }
        // for(int i=0;i<3;i++){
        //     for(int j=0;j<3;j++){
        //         printf("%d ",ans.a[i][j]);
        //     }
        //     printf("\n");
        // }
        cout << (((ans.a[0][0]+ans.a[1][0])%MOD)+ans.a[2][0])%MOD << "\n";
    }
    // while(1);
    return 0;
}