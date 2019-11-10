/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
string str[100100];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> str[i];
    sort(str,str+n);
    for(int i=0;i<n;i++){
        cout << str[i];
        printf("\n");
    }
    return 0;
}
