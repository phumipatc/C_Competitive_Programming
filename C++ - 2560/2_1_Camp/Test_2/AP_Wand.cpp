/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
vector< int> g[100100];
int mic[100100];
int main(){
    int n,k,t,s,e;
    cin >> n >> k >> t;
    for(int i=1;i<=k;i++){
        scanf("%d %d",&s,&e);
        s++,e++;
        g[s].push_back(e);
    }
    for(int i=2;i<=n+1;i++)
        mic[i] = 1e9;
    for(int i=1;i<=n+1;i++){
        mic[i] = min(mic[i],mic[i-1]+1);
        for(int j=0;j<g[i].size();j++){
            mic[g[i][j]] = min(mic[g[i][j]],mic[i]+1);
        }
    }
    cout << mic[n+1] << endl;
    if(mic[n+1] <= t){
        cout << "1" << endl;
    }else{
        cout << "0 ";
        for(int i=n;i>0;i--){
            if(mic[i] <= t){
                cout << i-1 << endl;
                return 0;
            }
        }
    }
    return 0;
}
