/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > g[30100];
int lv[30100],p[30100];
void dfs(int now,int state){
    lv[now] = state;
    for(auto &x:g[now]){
        if(lv[x] == 0){
            p[x] = now;
            dfs(x,state+1);
        }
    }
}
int main(){
    int n,m,a,b,countt,temp;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,1);
    scanf("%d",&m);
    a = 1,countt = 0;
    while(m--){
        scanf("%d",&b);
        temp = b;
        while(lv[a]!=lv[b]){
            countt++;
            if(lv[a]>lv[b]) a = p[a];
            else            b = p[b];
        }
        while(a!=b){
            countt+=2;
            a = p[a];
            b = p[b];
        }
        a = temp;
    }
    printf("%d\n",countt);
    return 0;
}
