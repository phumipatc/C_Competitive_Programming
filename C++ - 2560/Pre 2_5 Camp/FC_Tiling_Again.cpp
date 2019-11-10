/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 1000000009
using namespace std;
struct A{
    long long a[4][4];
};
A temp;
A multi(A a,A b){
    memset(temp.a,0,sizeof temp.a);
    for(long long i=0;i<4;i++){
        for(long long j=0;j<4;j++){
            for(long long k=0;k<4;k++){
                temp.a[i][j]+=a.a[i][k]*b.a[k][j];
                temp.a[i][j]%=MOD;
            }
        }
    }
    return temp;
}
A p[51],mul,ans;
int main(){
    long long n,q;
    p[0] = {{1,1,2,0,1,0,0,0,0,1,1,0,1,1,2,1}};
    mul = {{1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0}};
    for(long long i=1;i<50;i++)
        p[i] = multi(p[i-1],p[i-1]);
    cin >> q;
    while(q--){
        cin >> n;
        if(n == 1){
            cout << "1" << endl;
            continue;
        }
        n--;
        ans={{1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1}};
        for(long long i=0;i<50;i++)
            if(n & (1ll<<i))
                ans=multi(ans,p[i]);
        ans=multi(ans,mul);
        cout << ans.a[3][0] << endl;
    }
    return 0;
}
