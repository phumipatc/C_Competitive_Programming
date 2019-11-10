#include<bits/stdc++.h>
using namespace std;
struct A
{
    int to;
    int w;
}tree;
vector< A> a[100100];
queue< A> z;
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        int n,m,ans=-1,from,o;
        scanf("%d %d",&n,&m);
        o=n;
        n=n-1;
        while(n--){
            scanf("%d %d %d",&from,&tree.to,&tree.w);
            a[from].push_back(tree);
        }
        tree.to = 1,tree.w = 0;
        z.push(tree);
        while(!z.empty()){
            int now=z.front().to,wa=z.front().w;
            z.pop();
            int siz = a[now].size();
            ans = max(ans,wa);
            for(int i=0;i<siz;i++)
                tree.to = a[now][i].to,tree.w = a[now][i].w + wa,z.push(tree);
        }
        if(ans >= m)
            printf("%d\n",ans);
        else
            printf("-1\n");
        for(int i=1;i<o;i++)
            a[i].clear();
    }
    return 0;
}
