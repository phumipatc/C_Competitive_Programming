/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char s[5];
vector< int> g[30];
int degree[30],n,ans[310],mark[30][30],idx;
void find_way(int state,int now){
    ans[state]=now;
    if(state==n){
        for(int i=0;i<=n;i++)   printf("%c ",ans[i]+'A');
        exit(0);
    }
    for(int i=0;i<g[now].size();i++){
        if(mark[now][g[now][i]])    continue;
        mark[now][g[now][i]]=mark[g[now][i]][now]=1;
        find_way(state+1,g[now][i]);
        mark[now][g[now][i]]=mark[g[now][i]][now]=0;
    }
}
int main(){
    int countt=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %s",s);
        g[s[0]-'A'].push_back(s[1]-'A');
        g[s[1]-'A'].push_back(s[0]-'A');
        degree[s[0]-'A']++;
        degree[s[1]-'A']++;
    }
    for(int i=0;i<26;i++){
        sort(g[i].begin(),g[i].end());
        if(degree[i]%2==1){
            countt++;
        }
    }
    if(countt==2){
        for(int i=0;i<26;i++){
            if(degree[i]%2==1){
                find_way(0,i);
                break;
            }
        }
    }else{
        for(int i=0;i<26;i++){
            if(degree[i]!=0){
                find_way(0,i);
                break;
            }
        }
    }
    return 0;
}
