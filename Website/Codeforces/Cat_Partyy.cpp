/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int ribbon[500010],countt[500010];
set<int > sett;
int main(){
    int n,temp,ans;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> temp;
        ribbon[temp]++;
        if(ribbon[temp] != 1){
            
        }
        countt[ribbon[temp]]++;
    }
	return 0;
}
