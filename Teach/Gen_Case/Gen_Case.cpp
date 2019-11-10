/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define MOD 40
using namespace std;
typedef long long LL;
int main(){
    // ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    // freopen("10.in","w",stdout);
    srand(time(NULL));
    int q = 5;
    cout << q << endl;
    while(q--){
        int l,r,num,dif;
        l = r = rand();
        while(l == r || r>1000000 || dif<800000 || dif>1000000){
            dif = 0;
            num = (rand()%MOD)+1;
            for(int i=1;i<=num;i++){
                dif+=rand();
            }
            r = l+dif;
            // printf("%d %d\n",dif,r);
        }
        cout << l << " " << r << endl;
    }
    return 0;
}