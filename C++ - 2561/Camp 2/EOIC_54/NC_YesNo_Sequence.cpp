/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
string str;
map<string ,int > mapp;
int a[2510];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin >> str;
        mapp[str] = i;
    }
    for(int i=1;i<=n;i++){
        cin >> str;
        a[i] = mapp[str];
    }
    int ans = 0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            if(a[j]>a[i])   ans++;
        }
    }
    printf("%d/%d\n",ans,n*(n-1)/2);
	return 0;
}
