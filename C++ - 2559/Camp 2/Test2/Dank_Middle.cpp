/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector< int> g[12000];
int main(){
    int n,a,b;
    scanf("%d",&n);
    for(i=0;i<n-1;i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
return 0;
}
