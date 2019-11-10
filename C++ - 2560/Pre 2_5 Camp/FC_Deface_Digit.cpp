/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
deque<int > deq;
char str[500005];
int main(){
    int n,k;
    cin >> n >> k >> str+1;
    for(int i=1;i<=n;i++){
        while(!deq.empty() && str[i]-'0'>deq.back() && k)
            deq.pop_back(),k--;
        deq.push_back(str[i]-'0');
    }
    while(!deq.empty() && k)
        deq.pop_back(),k--;
    while(!deq.empty()){
        cout << deq.front();
        deq.pop_front();
    }
    return 0;
}
