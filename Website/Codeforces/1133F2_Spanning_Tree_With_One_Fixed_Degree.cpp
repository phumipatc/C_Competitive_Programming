/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int u,v;
};
struct B{
    int v,w;
};
A a[200010];
queue<int > que;
vector<B > g[200010];
int connect[200010],p[200010],use[200010];
int find_root(int u){
    if(p[u] == u)   return u;
    else            return p[u] = find_root(p[u]);
}
int main(){
    ios_base::sync_with_stdio(0);   cin.tie(0);
    int n,m,d,deg = 0;
    cin >> n >> m >> d;
    for(int i=1;i<=m;i++){
        cin >> a[i].u >> a[i].v;
        if(a[i].u>a[i].v)   swap(a[i].u,a[i].v);
        if(a[i].u == 1){
            deg++;
            connect[a[i].v] = 1;
            use[i] = 1;
        }
        g[a[i].u].push_back({a[i].v,i});
        g[a[i].v].push_back({a[i].u,i});
    }
    if(deg<d){
        printf("NO\n");
        return 0;
    }
    for(int i=1;i<=n;i++)
        p[i] = i;
    for(auto x:g[1])    que.push(x.v);
    int ru,rv;
    while(!que.empty()){
        int now = que.front();
        que.pop();
        for(auto x:g[now]){
            ru = find_root(now);
            rv = find_root(x.v);
            if(x.v == 1)    continue;
            if(ru == rv)    continue;
            if(connect[ru] && connect[rv]){
                if(deg>d){
                    p[ru] = rv;
                    connect[ru] = 0;
                    deg--;
                    use[x.w] = 1;
                }
                continue;
            }else if(connect[ru]){
                use[x.w] = 1;
                p[rv] = ru;
                que.push(x.v);
            }else if(connect[rv]){
                use[x.w] = 1;
                p[ru] = rv;
            }
        }
    }
    if(deg>d){
        printf("NO\n");
        return 0;
    }
    for(auto x:g[1]){
        if(!connect[x.v])
            use[x.w] = 0;
    }
    printf("YES\n");
    for(int i=1;i<=m;i++){
        if(use[i]){
            printf("%d %d\n",a[i].u,a[i].v);
        }
    }
    return 0;
}
/*
5 4 2
3 1
1 5
4 5
4 2
*/