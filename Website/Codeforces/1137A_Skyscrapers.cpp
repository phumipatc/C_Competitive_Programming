/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > r[1010],c[1010];
int a[1010][1010];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0);
    int n,m,idx;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> a[i][j];
            r[i].push_back(a[i][j]);
            c[j].push_back(a[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        sort(r[i].begin(),r[i].end());
        r[i].resize(unique(r[i].begin(),r[i].end())-r[i].begin());
    }
    for(int i=1;i<=m;i++){
        sort(c[i].begin(),c[i].end());
        c[i].resize(unique(c[i].begin(),c[i].end())-c[i].begin());
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int ir = upper_bound(r[i].begin(),r[i].end(),a[i][j])-r[i].begin();
            int ic = upper_bound(c[j].begin(),c[j].end(),a[i][j])-c[j].begin();
            if(ir == ic)
                cout << max(r[i].size(),c[j].size()) << " ";
            else if(ir>ic)
                cout << max(r[i].size(),c[j].size()+ir-ic) << " ";
            else
                cout << max(r[i].size()+ic-ir,c[j].size()) << " ";
        }
        cout << "\n";
    }
	return 0;
}