/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
    int n,q,d;
    cin >> n >> q >> d;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    while(q--){
        int st,en,ch=0;
        cin >> st >> en;
        for(int i=st;i<en;i++){
            for(int j=i+1;j<=en;j++){
                if(abs(a[i]-a[j])==d)
                    ch=1;
            }
        }
        if(ch)  cout << "yes" << endl;
        else    cout << "no" << endl;
    }
    return 0;
}
