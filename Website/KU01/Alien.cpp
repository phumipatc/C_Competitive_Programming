/*
    Author	: Phumipat C.
    School	: RYW
    Langauge: C++
    Algo	: Implementing
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
double dist(pair<int ,int > st,pair<int ,int > now){
    return sqrt(pow((double )st.first-now.first,2)+pow((double )st.second-now.second,2));
}
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,r,ans = 0;
    pair<int ,int > st,now;
    cin >> n >> st.first >> st.second >> r;
    while(n--){
        cin >> now.first >> now.second;
        if(dist(st,now)<=r)   ans++;
    }
    cout << ans << '\n';
}