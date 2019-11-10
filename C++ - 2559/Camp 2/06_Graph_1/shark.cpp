/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector< int> g[1200];
int shark[1200];
int main(){
    int n,m,a,b;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",&shark[i]);
    while(m--){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
    }
return 0;
}
