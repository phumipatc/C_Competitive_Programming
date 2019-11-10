/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
#define END 1000000
using namespace std;
struct A{
    int near,x,y;
};
A ans;
int p[1000010],dp[1000010];
vector<int> prime;
int main(){
    int A,B,C,D;
    cin >> A >> B >> C >> D;
    p[2] = 1;
    for(int i=3;i<=END;i+=2)    p[i] = 1;
    for(int i=3;i<=END;i++)
        if(p[i])
            for(int j=2*i;j<=END;j+=i)
                p[j] = 0;
    memset(dp,-1,sizeof dp);
    for(int i=2;i<=END;i++)
        if(p[i])
            prime.push_back(i),dp[i] = 1;
    dp[1] = 0;
    for(auto &i:prime)
        for(int j=2*i;j<=END;j+=i)
            if(dp[j/i]!=-1)
                dp[j] = dp[j/i]+1;
    ans.near = -1e9;
    for(int i=1;i<=B;i++){
        if(((B/i)-((A-1)/i)) && ((D/i)-((C-1)/i))){
            if(ans.near<dp[i]){
                ans.near = dp[i];
                ans.x = (B/i)*i;
                ans.y = (D/i)*i;
            }else if(ans.near == dp[i]){
                if(ans.x+ans.y<(B/i)*i+(D/i)*i){
                    ans.x = (B/i)*i;
                    ans.y = (D/i)*i;
                }else if(ans.x+ans.y==(B/i)*i+(D/i)*i && ans.x<(B/i)*i){
                    ans.x = (B/i)*i;
                }
            }
        }
    }
    cout << ans.x << ' ' << ans.y << endl;
    return 0;
}
