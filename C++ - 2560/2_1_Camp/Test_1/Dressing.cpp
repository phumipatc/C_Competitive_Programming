/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int ans[50100],in_degree[50100],in_degree2[50100];
vector< int> v[50100];
priority_queue< int> heap;
int main()
{
    int n,m,a,b;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        v[b].push_back(a);
        in_degree[a]++;
        in_degree2[a]++;
    }
    for(int i=1;i<=n;i++)
        if(in_degree[i]==0)
            heap.push(i*(-1));
    int idx=-1,now=1;
    while(!heap.empty()){
        int x=heap.top()*(-1);
        heap.pop();
        if(heap.size()>=1){
            idx=now;
        }
        ans[now]=x;
        now++;
        for(int i=0;i<v[x].size();i++){
            in_degree[v[x][i]]--;
            if(in_degree[v[x][i]]==0)   heap.push(v[x][i]*(-1));
        }
    }
    if(now!=n+1){
        cout << "Never" << endl;
        return 0;
    }
    if(idx==-1){
        cout << "Same" << endl;
        for(int i=1;i<now;i++)   cout << ans[i] << " ";
        return 0;
    }
    for(int i=1;i<=n;i++)
        if(in_degree2[i]==0)
            heap.push(i*(-1));
    now=1;
    while(!heap.empty()){
        int x=heap.top()*(-1);
        heap.pop();
        if(idx==now){
            int y=heap.top()*(-1);
            heap.pop();
            heap.push(x*(-1));
            x=y;
        }
        ans[now]=x;
        now++;
        for(int i=0;i<v[x].size();i++){
            in_degree2[v[x][i]]--;
            if(in_degree2[v[x][i]]==0)   heap.push(v[x][i]*(-1));
        }
    }
    cout << "Different" << endl;
    for(int i=1;i<now;i++)   cout << ans[i] << " ";
    return 0;
}
/*
4 4
2 1
3 1
4 2
4 3
*/
