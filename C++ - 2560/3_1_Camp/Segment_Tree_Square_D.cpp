/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int cluster[320],a[100010];
int main(){
    int n,q,sq,x,y,ans;
    char opr;
    cin >> n >> q;
    sq = sqrt(n);
    while(q--){
        cin >> opr >> x >> y;
        ans = -1e9;
        x--;
        if(opr == 'U'){
            a[x] = y;
            cluster[x/sq] = -1e9;
            for(int i=(x/sq)*sq;i<=min(n,((x/sq)*sq)+sq);i++)
                cluster[x/sq] = max(cluster[x/sq],a[i]);
        }else{
            y--;
            for(int i=x;i<=y;){
                if(i%sq==0 && i+sq-1<=y){
                    ans=max(ans,cluster[i/sq]);
                    i+=sq;
                }else
                    ans=max(ans,a[i++]);
            }
            cout << ans << endl;
        }
    }
    return 0;
}
