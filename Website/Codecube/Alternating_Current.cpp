/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int countt[100010];
set<int > sett;
set<int > ::iterator minn,maxx;
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0),cout.tie(0);
    int n,k,num,ans = 0;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> num;
        countt[num]++;
        sett.insert(num);
    }
    minn = sett.begin();
    maxx = sett.end(),maxx--;
    while(*maxx-*minn>k){
        // printf("%d %d %d %d\n",*minn,*maxx,countt[*minn],countt[*maxx]);
        if(countt[*maxx] == countt[*minn]){
            ans+=countt[*maxx];
            countt[*maxx-1]+=countt[*maxx];
            countt[*minn+1]+=countt[*minn];
            sett.insert(*maxx-1);
            sett.insert(*minn+1);
            sett.erase(maxx);
            sett.erase(minn);
        }else if(countt[*maxx]>countt[*minn]){
            ans+=countt[*minn];
            countt[*maxx-1]+=countt[*minn];
            countt[*maxx]-=countt[*minn];
            countt[*minn+1]+=countt[*minn];
            sett.insert(*maxx-1);
            sett.insert(*minn+1);
            sett.erase(minn);
        }else if(countt[*maxx]<countt[*minn]){
            ans+=countt[*maxx];
            countt[*minn+1]+=countt[*maxx];
            countt[*minn]-=countt[*maxx];
            countt[*maxx-1]+=countt[*maxx];
            sett.insert(*minn+1);
            sett.insert(*maxx-1);
            sett.erase(maxx);
        }
        minn = sett.begin();
        maxx = sett.end(),maxx--;
    }
    printf("%d\n",ans);
    return 0;
}