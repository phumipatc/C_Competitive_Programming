/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
vector< double> g[110][110];
queue< int> q;
int mark[110];
int main()
{
    char u,v;
    int n,i,ch=1;
    double sum=0,d;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf(" %c %c %lf",&u,&v,&d);
        g[u-'A'][v-'A'].push_back(d);
        g[v-'A'][u-'A'].push_back(d);
    }
    q.push('X'-'A');
    while(!q.empty()){
        int now=q.front();
        q.pop();
        if(mark[now]==1)    continue;
        mark[now]=1;
        for(i=32;i<58;i++){
            if(g[now][i].size()!=0 && mark[i]==0){
                q.push(i);
            }
        }
        if(g[now]['Y'-'A'].size()!=0){
            ch=0;
            break;
        }
    }
    if(ch){
        printf("broken\n");
        return 0;
    }
    memset(mark,0,sizeof mark);
    while(!q.empty())   q.pop();
    q.push('X'-'A');
    while(!q.empty()){
        int now=q.front();
        q.pop();
        if(mark[now]==1)    continue;
        mark[now]=1;
        for(i=32;i<58;i++){
            if(g[now][i].size()!=0 && mark[i]==0){
                sort(g[now][i].begin(),g[now][i].end());
                if(g[now][i].size()%2==1){
                    printf("%c %c %.1lf\n",now+'A',i+'A',g[now][i][g[now][i].size()/2]);
                    sum+=g[now][i][g[now][i].size()/2];
                }else{
                    printf("%c %c %.1lf\n",now+'A',i+'A',(g[now][i][(g[now][i].size()-1)/2]+g[now][i][(g[now][i].size()-1)/2+1])/2);
                    sum+=(g[now][i][(g[now][i].size()-1)/2]+g[now][i][(g[now][i].size()-1)/2+1])/2;
                }
                q.push(i);
            }
        }
        if(g[now]['Y'-'A'].size() != 0){
            sort(g[now]['Y'-'A'].begin(),g[now]['Y'-'A'].end());
            if(g[now]['Y'-'A'].size()%2==1){
                printf("%c %c %.1lf\n",now+'A','Y',g[now]['Y'-'A'][g[now]['Y'-'A'].size()/2]);
                sum+=g[now]['Y'-'A'][g[now]['Y'-'A'].size()/2];
            }else{
                printf("%c %c %.1lf\n",now+'A','Y',(g[now]['Y'-'A'][(g[now]['Y'-'A'].size()-1)/2]+g[now]['Y'-'A'][(g[now]['Y'-'A'].size()-1)/2+1])/2);
                sum+=(g[now]['Y'-'A'][(g[now]['Y'-'A'].size()-1)/2]+g[now]['Y'-'A'][(g[now]['Y'-'A'].size()-1)/2+1])/2;
            }
            printf("%.1lf\n",sum);
            return 0;
        }
    }
    return 0;
}
/*
6
X a 1
a b 4
b a 1
b Y 3
b Y 2
Y b 6

3
X a 2
c b 3
b Y 3

5
q Y 3
X a 1
a b 2
t b 4
q t 5
*/
