/*
    Author	: Phumipat C. [MAGCARI]
    School	: RYW
    language: C++
    Algo	: Implementing
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
int sumr[110],sumc[110];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n;
    char c;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> c;
            if(c == '.')    continue;
            sumr[i]++;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sumr[i];j++)
            sumc[j]++;
    }
    for(int j=1;j<=n;j++)
        sumc[j] = n-sumc[j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i<=sumc[j])  cout << '.';
            else            cout << '#';
        }
        cout << '\n';
    }
    return 0;
}