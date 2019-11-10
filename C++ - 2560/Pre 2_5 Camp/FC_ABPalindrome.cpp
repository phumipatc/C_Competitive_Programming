/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int temp = (int)ceil((double)i/2);
        if(temp%2 == 1) cout << "a";
        else            cout << "b";
    }
    return 0;
}

