/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<long long > pos;
long long rr,s;
long long divide(long long l,long long r){
    long long num;
    if(l == r){
        num = upper_bound(pos.begin(),pos.end(),r)-pos.begin();
        num -= upper_bound(pos.begin(),pos.end(),l-1)-pos.begin();
        if(num) return s*num;
        else    return rr;
    }
    num = upper_bound(pos.begin(),pos.end(),r)-pos.begin();
    num -= upper_bound(pos.begin(),pos.end(),l-1)-pos.begin();
    long long mid = (l+r)/2;
    if(num){
        return min(s*num*(r-l+1),divide(l,mid)+divide(mid+1,r));
    }else{
        return rr;
    }
}
int main(){
    long long n,c,temp;
    cin >> n >> c >> rr >> s;
    while(c--){
        cin >> temp;
        pos.push_back(temp);
    }
    sort(pos.begin(),pos.end());
    cout << divide(1,1<<n);
	return 0;
}
