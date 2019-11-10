/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 997
using namespace std;
struct A{
    int a[2][2];
};
A temp;
A multi(A a,A b){
    memset(temp.a,0,sizeof temp.a);
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                temp.a[i][j]+=a.a[i][k]*b.a[k][j];
                temp.a[i][j]%=MOD;
            }
        }
    }
    return temp;
}
A p[32],ans,mul;
int main(){
    p[0] = {{3,4,1,0}};
    mul = {{2,0,3,0}};
    for(int i=1;i<32;i++)
        p[i] = multi(p[i-1],p[i-1]);
    int q,n;
    cin >> q;
    while(q--){
        cin >> n;
        if(n == 0){
            cout << "3 ";
            continue;
        }
        if(n == 1){
            cout << "2 ";
            continue;
        }
        n--;
        ans = {{1,0,0,1}};
        for(int i=0;i<32;i++)
            if(n&(1<<(i)))
                ans = multi(ans,p[i]);
        ans = multi(ans,mul);
        cout << ans.a[0][0] << " ";
    }
    return 0;
}
