/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
pair<int ,int > minl,minr,maxl,maxr;
char a[10010][2010];
int dir[2][4] = {{-1,1,0,0},{0,0,1,-1}};
queue<pair<int ,int >> que;
int main(){
    int n,m,ni,nj,sq = 0,tri = 0,dia = 0,ch;
    pair<int ,int > now;
    scanf("%d %d",&m,&n);
    for(int i=1;i<=n;i++)
        scanf(" %s",a[i]+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j] == '0')  continue;
            ch = 0;
            if(a[i][j+1] != '1' && a[i+1][j] == '1' && ((a[i+1][j+1] == '1' && a[i+1][j-1] != '1') || (a[i+1][j+1] != '1' && a[i+1][j-1] == '1'))){
                ch = 1;
                tri++;
            }
            minl = minr = {1e9,1e9};
            maxl = maxr = {-1e9,-1e9};
            que.push({i,j});
            a[i][j] = '0';
            while(!que.empty()){
                now = que.front();
                que.pop();
                // printf("%d %d\n",now.first,now.second);
                if(minl.first>now.first){
                    minl = now;
                }else if(minl.first == now.first){
                    minl.second = min(minl.second,now.second);
                }
                if(minr.first>now.first){
                    minr = now;
                }else if(minr.first == now.first){
                    minr.second = max(minr.second,now.second);
                }
                if(maxl.first<now.first){
                    maxl = now;
                }else if(maxl.first == now.first){
                    maxl.second = min(maxl.second,now.second);
                }
                if(maxr.first<now.first){
                    maxr = now;
                }else if(maxr.first == now.first){
                    maxr.second = max(maxr.second,now.second);
                }
                for(int k=0;k<4;k++){
                    ni = now.first+dir[0][k];
                    nj = now.second+dir[1][k];
                    if(ni<1 || nj<1 || ni>n || nj>m)    continue;
                    if(a[ni][nj] == '0')                continue;
                    a[ni][nj] = '0';
                    que.push({ni,nj});
                }
            }
            if(ch)  continue;
            // printf("%d %d %d %d\n",minl.first,minl.second,minr.first,minr.second);
            // printf("%d %d %d %d\n",maxl.first,maxl.second,maxr.first,maxr.second);
            if(minl != minr && maxl != maxr)        sq++;
            else if(minl != minr && maxl == maxr)   tri++;
            else if(minl == minr && maxl != maxr)   tri++;
            else                                    dia++;
            // printf("%d %d : %d %d %d\n",i,j,sq,dia,tri);
        }
    }
    printf("%d %d %d\n",sq,dia,tri);
	return 0;
}
