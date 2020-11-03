/*
    Author	: Phumipat C. [MAGCARI]
    School	: RYW
    Langauge: C++
    Algo	: Implementing
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
PII p[110];
int dist(PII a,PII b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,minn = 1e9,sum;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> p[i].first >> p[i].second;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            sum = 0;
            for(int k=1;k<=n;k++)
                sum+=min(dist(p[k],p[i]),dist(p[k],p[j]));
            minn = min(minn,sum);
        }
    }
    cout << minn << '\n';
}