/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[32][32];
int countt,n,m,dir[2][4] = {{0,-1,0,1},{-1,0,1,0}};
void dfs(int i,int j){
    for(int k=0;k<4;k++){
        int ni = i+dir[0][k];
        int nj = j+dir[1][k];
        int ch = 1;
        if(ni<1 || nj<1 || ni>n || nj>m)    continue;
        if(a[ni][nj] != '.')                continue;
        a[ni][nj] = '%';
        for(int l=0;l<4;l++){
            int nii = ni+dir[0][l];
            int njj = nj+dir[1][l];
            if(nii<1 || njj<1 || nii>n || njj>m)    continue;
            if(nii == i && njj == j)                continue;
            if(a[nii][njj] == '#'){
                ch = 0;
                break;
            }
        }
        if(ch){
            countt++;
            dfs(ni,nj);
        }
    }
}
int main(){
    int ans = 0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf(" %c",&a[i][j]);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j] == '.' && a[i-1][j]!='#' && a[i+1][j]!='#' && a[i][j-1]!='#' && a[i][j+1]!='#'){
                countt = 1;
                a[i][j] = '%';
                dfs(i,j);
                ans = max(ans,countt);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
3 10
....##...#
...#.#..##
....###...

4 6
..#...
.#.##.
..#..#
.#...#
*/
