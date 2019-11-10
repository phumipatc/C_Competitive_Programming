/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
pair<int,int> p[15];
int ans = 1e9,n;
void permute(int state,int a,int b,int countt){
    if(state == n){
        if(countt == n) return ;
        ans = min(ans,abs(a-b));
        return ;
    }
    permute(state+1,a*p[state].first,b+p[state].second,countt);
    permute(state+1,a,b,countt+1);
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> p[i].first >> p[i].second;
    permute(0,1,0,0);
    printf("%d\n",ans);
    return 0;
}
