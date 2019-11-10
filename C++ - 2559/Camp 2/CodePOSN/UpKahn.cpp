#include<bits/stdc++.h>
using namespace std;
vector<int>a[100100];
int mark[100100],ans[100100],n,m,in[100100],num;
priority_queue<int>b;
int main()
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        num = 0;
        scanf("%d %d",&n,&m);
        while(m--)
        {
            int A,B;
            scanf("%d %d",&A,&B);
            a[A].push_back(B);
            in[B]++;
        }
        for(int i=1;i<=n;i++)
            if(in[i]==0)
                b.push(-i);
        while(!b.empty())
        {
            int now = -b.top();
            int siz = a[now].size();
            b.pop();
            ans[num] = now;
            num++;
            for(int i=0;i<siz;i++){
                in[a[now][i]]--;
                if(in[a[now][i]] == 0)
                    b.push(-a[now][i]);
            }
        }
        if(num == n){
            printf("Yes");
            for(int i=0;i<n;i++)
                printf("%d ",ans[i]);
            printf("\n");
        }
        else{
            printf("No");
            printf("\n");
        }
        while(!b.empty())
            b.pop();
        for(int i=0;i<=n;i++)
            a[i].clear(),in[i]=0;
    }
    return 0;
}
