/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[310];
int a[310][310];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int ch = 1;
            for(int k=1;k<=n;k++){
                if(k == i || k == j)    continue;
                if(a[i][j] == a[i][k]+a[k][j]){
                    ch = 0;
                    break;
                }
            }
            if(ch){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    int maxx = 0,ans;
    for(int i=1;i<=n;i++){
        if(maxx<g[i].size()){
            maxx = g[i].size();
            ans = i;
        }
    }
    if(m == 1)  printf("%d\n",ans);
    else        printf("%d\n%d\n",ans,maxx);
    return 0;
}
