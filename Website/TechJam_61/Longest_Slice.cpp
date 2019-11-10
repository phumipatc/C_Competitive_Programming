/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> A;
int qs[100010];
int mark[200010],S;
int solution() {
    int ans = -1;
    for(int i=0;i<=200000;i++)
        mark[i] = 1e9;
    mark[100000] = 0;
    for(int i=1;i<=A.size();i++){
        qs[i] = qs[i-1]+A[i-1];
        mark[qs[i]+100000] = min(mark[qs[i]+100000],i);
    }
    for(int i=1;i<=A.size();i++){
        if(i == mark[qs[i]+100000-S])  continue;
        ans = max(ans,i-mark[qs[i]+100000-S]);
    }
    return ans;
}
int main(){
    int n,num;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num;
        A.push_back(num);
    }
    cout << solution();
    return 0;
}
