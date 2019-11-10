/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
map<int ,int > mapp;
vector<int > ans;
int a[100010];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int q,n,countt = 0;
    cin >> q;
    while(q--){
        cin >> n;
        for(int i=1;i<=n;i++){
            cin >> a[i];
            mapp[a[i]]++;
        }
        countt = 0;
        for(int i=1;i<=n;i++){
            if(mapp[a[i]]>1)    continue;
            countt++;
            ans.push_back(a[i]);
        }
        if(countt == 0) printf("No Alone Num\n");
        else{
            printf("%d\n",countt);
            for(auto x:ans)
                printf("%d ",x);
            printf("\n");
        }
        mapp.clear();
        ans.clear();
    }
    return 0;
}