/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<bits/stdc++.h>
using namespace std;
map<string,int> m;
vector<int> v[50];
queue<int> q;
int s[50],s2[50];
int main()
{
    int mm,n,p,nub=0;
    char c[5],c2[5];
    scanf("%d %d %d",&mm,&n,&p);
    for(int i=0;i<mm;i++)
    {
        scanf(" %s",c);
        m[c]=nub;
        nub++;
    }
    for(int i=0;i<n;i++)
    {
        scanf(" %s %s",c,c2);
        v[m[c]].push_back(m[c2]);
        v[m[c2]].push_back(m[c]);
    }
    int r,u,nu;
    for(int i=0;i<p;i++)
    {
        scanf("%d %s %s",&r,c,c2);
        q.push(m[c]);
        s2[m[c]]=1;
        while(!q.empty())
        {
            u=q.front();
            q.pop();
            for(int j=0;j<(int)v[u].size();j++)
            {
                nu=v[u][j];
                if(s[nu]==0 && s2[nu]==0)
                {
                    s[nu]=s[u]+1;
                    q.push(nu);
                    s2[nu]=1;
                }
            }
        }
        if(s2[m[c2]]==0)
            printf("NO SHIPMENT POSSIBLE\n");
        else
        printf("%s %s %d\n",c,c2,s[m[c2]]*1128*r);
        for(int j=0;j<mm;j++)
        {
            s[j]=0;
            s2[j]=0;
        }
    }
}
/*
6 7 4
aa cc qr ff dd ab
aa cc cc qr dd cc aa dd aa ab dd qr ab dd
2 aa ab
1 dd cc
3 cc dd
7 aa ff

*/
