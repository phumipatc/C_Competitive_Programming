/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>v[300010];
long long val[300010];
int mark[300010];
vector<long long>ans;
queue<int>q;
int main()
{
    //freopen("input20.in","r",stdin);
    //freopen("output20.out","w",stdout);
    int n,m,Q,N,k,x,y,A,B;
    long long a,b;
    long long now = 0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%lld",&val[i]);
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        scanf("%lld %lld",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        if(!mark[i])
        {
            now = 0;
            q.push(i);
            while(!q.empty())
            {
                N = q.front();
                q.pop();
                if(mark[N])continue;
                mark[N] = 1,now += (long long)val[N];
                for(int i=0;i<v[N].size();i++)
                {
                    if(!mark[v[N][i]])
                        q.push(v[N][i]);
                }
            }
            ans.push_back(now);
        }
    }
    sort(ans.begin(),ans.end());
    /*for(int i = 0;i<ans.size();i++)
        printf("%lld\n",ans[i]);*/
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d",&k);
        if(k == 1)
        {
            scanf("%lld",&a);
            A = lower_bound(ans.begin(),ans.end(),a) - ans.begin();
            printf("%s\n",(ans[A] == a) ? "MEENA":"MAIMEE");
        }
        if(k == 2)
        {
            scanf("%lld",&a);
            A = lower_bound(ans.begin(),ans.end(),a) - ans.begin();
            B = upper_bound(ans.begin(),ans.end(),a) - ans.begin();
            printf("%d\n",B-A);
        }
        if(k == 3)
        {
            scanf("%lld %lld",&a,&b);
            A = lower_bound(ans.begin(),ans.end(),a) - ans.begin();
            B = upper_bound(ans.begin(),ans.end(),b) - ans.begin();
            printf("%d\n",B-A);
        }
    }
    return 0;
}
