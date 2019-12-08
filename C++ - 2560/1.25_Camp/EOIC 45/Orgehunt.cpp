/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
string str;
int main(){
    int n,ans;
    cin >> n;
    for(n++;n>1;n/=2)
        ans = ((n&1)?"7":"4") + str;
    cout << str;
    return 0;
}
