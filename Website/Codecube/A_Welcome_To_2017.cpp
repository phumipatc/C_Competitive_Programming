/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int real,fake,s;
    bool operator < (const A&o) const{
        return s<o.s;
    }
};
A a[2020];
int countt[8010];
int main(){
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i].real;
        a[i].real = a[i].real;
        a[i].fake = a[i].real-2017;
    }
    for(int i=1;i<=n;i++){
        countt[a[i].fake+4000]++;
        a[i].s = abs(a[i].fake);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(countt[a[i].fake+4000] == 1){
            cout << a[i].real << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}
