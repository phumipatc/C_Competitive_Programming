/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > ans[1000005];
int countt[1000005];
int main(){
    int n,m,num,now,maxx;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> num;
            ans[i].push_back(num);
        }
        sort(ans[i].begin(),ans[i].end());
    }
    for(int i=0;i<m;i++){
        maxx = -1;
        for(int j=0;j<n;j++){
            if(maxx<ans[j][i]){
                maxx = ans[j][i];
                now = j;
            }
        }
        countt[now]++;
    }
    maxx = -1;
    for(int i=0;i<n;i++){
        if(maxx<countt[i]){
            maxx = countt[i];
            now = i;
        }
    }
    cout << now+1;
    return 0;
}
