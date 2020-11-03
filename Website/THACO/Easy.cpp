/*
    Author	: Phumipat C.
    School	: RYW
    Langauge: C++
*/
#include<bits/stdc++.h>
using namespace std;
string a,b,ans;
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int temp = 0,n,m;
    cin >> a >> b;
    n = a.length(),m = b.length();

    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    while(n<m)
        a.push_back('0'),n++;
    while(m<n)
        b.push_back('0'),m++;
    a.push_back('0'),b.push_back('0');
    n++;

    for(int i=0;i<n;i++){
        // printf("%d %d %d\n",a[i]-'0',b[i]-'0',temp);
        ans.push_back(((a[i]-'0'+b[i]-'0'+temp)%10)+'0');
        temp = (a[i]-'0'+b[i]-'0'+temp)/10;
    }
    while(!ans.empty() && ans.back() == '0')    ans.pop_back();
    if(ans.empty()) cout << "0\n";
    else{
        reverse(ans.begin(),ans.end());
        cout << ans << '\n';
    }
}