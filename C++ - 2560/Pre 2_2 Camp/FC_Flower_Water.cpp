/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector < int> x[1001000],y[1001000];
int p[1001000];
int find_root(int n){
    if(p[n]==n)   return p[n];
    return p[n]=find_root(p[n]);
}
int main()
{
    int q,n,i,rx,ry,ans,a,b,j;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        ans = n;
        for(i=1;i<=1000000;i++)
            p[i]=i;
        for(i=1;i<=n;i++){
            scanf("%d %d",&a,&b);
            x[a].push_back(i);
            y[b].push_back(i);
        }
        for(i=1;i<=1000000;i++){
            if(x[i].size()>0){
                rx = find_root(x[i][0]);
                for(j=1;j<x[i].size();j++){
                    ry = find_root(x[i][j]);
                    if(rx != ry){
                        p[ry] = rx;
                        ans--;
                    }
                }
            }
            x[i].clear();
        }
        for(i=1;i<=1000000;i++){
            if(y[i].size()>0){
                rx = find_root(y[i][0]);
                for(j=1;j<y[i].size();j++){
                    ry = find_root(y[i][j]);
                    if(rx != ry){
                        p[ry] = rx;
                        ans--;
                    }
                }
            }
            y[i].clear();
        }
        printf("%d\n",(ans+1)/2);
    }
    return 0;
}
/*
2
4
1 2
2 1
2 3
3 2
9
2 1
1 2
2 3
2 5
1 6
2 7
4 3
5 4
4 5
*/
