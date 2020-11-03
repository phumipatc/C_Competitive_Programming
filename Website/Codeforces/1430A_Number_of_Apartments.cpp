/*
    Author	: Phumipat C.
    School	: RYW
    Langauge: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
pair<int ,pair<int ,int > > mark[1010];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int q,n;
    for(int i=1;i<=1000;i++)
        mark[i].first = mark[i].second.first = mark[i].second.second = -1;
    for(int i=3;i<=1000;i++){
        if(i>=3 && mark[i-3].first!=-1){
            mark[i] = mark[i-3];
            mark[i].first++;
        }else if(i>=5 && mark[i-5].first!=-1){
            mark[i] = mark[i-5];
            mark[i].second.first++;
        }else if(i>=7 && mark[i-7].first!=-1){
            mark[i] = mark[i-7];
            mark[i].second.second++;
        }
    }
    cin >> q;
    while(q--){
        cin >> n;
        if(mark[n].first == -1){
            printf("%d\n",mark[n].first);
            continue;
        }
        printf("%d %d %d\n",mark[n].first,mark[n].second.first,mark[n].second.second);
    }
}