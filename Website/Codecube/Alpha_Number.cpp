/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int v[10],countt[10];
set<int > sett;
set<int > ::iterator it;
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,minn = 1e9,last,ch = 0;
    cin >> n;
    for(int i=0;i<10;i++){
        cin >> v[i];
        // if(i == 0)  continue;
        minn = min(minn,v[i]);
    }
    for(int i=9;i>=0;i--){
        if(v[i]!=minn)  continue;
        if(n>=v[i]){
            countt[i]+=n/v[i];
            sett.insert(i);
            n-=(n/v[i])*v[i];
            if(i == 0)  ch = 2;
            else        ch = 1;
        }
        last = i;
        break;
    }
    if(ch == 0){
        cout << "-1\n";
        return 0;
    }
    for(int i=9;i>last;i--){
        it = sett.begin();
        if(*it>=i)  break;
        int num = n/(v[i]-v[*it]);
        if(num>=countt[*it]){
            countt[*it] = 0;
            sett.erase(it);
            countt[i]+=countt[*it];
            sett.insert(i);
            n-=countt[*it]*(v[i]-v[*it]);
            i++;
            ch = 1;
        }else if(num!=0){
            countt[*it]-=num;
            countt[i]+=num;
            sett.insert(i);
            n-=num*(v[i]-v[*it]);
            ch = 1;
        }
    }
    if(ch == 2){
        minn = 1e9;
        for(int i=9;i>0;i--)
            minn = min(minn,(int )ceil((v[i]-n)/v[0]));
        for(int i=9;i>0;i--){
            if(minn!=(int )ceil((v[i]-n)/v[0])) continue;
            countt[i]++;
            countt[0]-=minn;
            break;
        }
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=countt[i];j++)
            cout << i;
    }
    return 0;
}