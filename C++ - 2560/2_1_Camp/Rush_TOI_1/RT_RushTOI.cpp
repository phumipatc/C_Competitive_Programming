/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int dis[310][310];
int main()
{
    int i,j,k,n,m,s,e,d;
    cin >> n >> m;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            dis[i][j]=1e9;
    for(i=1;i<=m;i++){
        cin >> s >> e >> d;
        dis[s][e]=min(dis[s][e],d);
    }
    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(dis[i][j]==1e9)
                cout << "0 ";
            else
                cout << dis[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
/*
4 5
1 2 10
2 3 10
1 3 15
4 4 10
4 1 10
*/
