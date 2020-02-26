/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y;
    bool operator < (const A&o) const{
        if(x!=o.x)  return x<o.x;
        else        return y<o.y;
    }
};
A a[100010];
int LIS[100010];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0);
    int n,maxx,idx;
    while(1){
        cin >> n;
        if(!n)  break;
        maxx = 0;
        for(int i=1;i<=n;i++)
            cin >> a[i].x >> a[i].y;
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            idx = upper_bound(LIS,LIS+maxx,a[i].y)-LIS;
            if(maxx == idx) maxx++;
            LIS[idx] = a[i].y;
        }
        cout << maxx << "\n";
        memset(LIS,0,sizeof LIS);
    }
    return 0;
}