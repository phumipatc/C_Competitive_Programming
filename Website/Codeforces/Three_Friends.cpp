/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
vector<int > v;
int dist(){
    return abs(v[0]-v[1])+abs(v[1]-v[2])+abs(v[0]-v[2]);
}
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int q,num;
    cin >> q;
    while(q--){
        for(int i=1;i<=3;i++){
            cin >> num;
            v.push_back(num);
        }
        sort(v.begin(),v.end());
        if(v[0] == v[1] && v[1]!=v[2]){
            v[2]--;
            if(v[2]!=v[1])  v[0]++,v[1]++;
        }else if(v[1] == v[2] && v[1]!=v[0]){
            v[0]++;
            if(v[0]!=v[1])  v[1]--,v[2]--;
        }else if(v[1]!=v[2] && v[0]!=v[1]){
            v[0]++;
            v[2]--;
        }
        cout << dist() << '\n';
        v.clear();
    }
    return 0;
}