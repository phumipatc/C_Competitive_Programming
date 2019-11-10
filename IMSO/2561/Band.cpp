/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
pair<int,int> p[5100];
int mark[1100][1100],ans[3];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d %d",&p[i].first,&p[i].second);
        mark[p[i].first][p[i].second] = mark[p[i].second][p[i].first] = 1;
    }
    for(int i=1;i<m;i++){
        for(int j=i+1;j<=m;j++){
            if(p[i].first == p[j].first || p[i].first == p[j].second)   continue;
            if(p[i].second == p[j].first || p[i].second == p[j].second) continue;
            int countt = 2;
            if(mark[p[i].first][p[j].first])    countt++;
            if(mark[p[i].first][p[j].second])   countt++;
            if(mark[p[i].second][p[j].first])   countt++;
            if(mark[p[i].second][p[j].second])  countt++;
            if(countt == 5) ans[0]++;
            if(countt == 6) ans[1]++;
        }
    }
    printf("%d\n",(ans[0]/2)+(ans[1]/3));
    return 0;
}
