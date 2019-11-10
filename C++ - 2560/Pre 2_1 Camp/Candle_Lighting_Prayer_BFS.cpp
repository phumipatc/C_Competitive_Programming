/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int x,y;
};
long long r,c,a[2100][2100],dir[8][2]={{-1,0},{1,0},{0,1},{0,-1},{-1,1},{1,1},{-1,-1},{1,-1}};
queue< A> q;
int main()
{
    char t;
    long long i,j,ans=0,k,l,m;
    scanf("%lld %lld",&r,&c);
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            scanf(" %c",&t);
            a[i][j]=t-'0';
        }
    }
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            if(a[i][j]){
                ans++;
                a[i][j]=0;
                q.push({i,j});
                while(!q.empty()){
                    k=q.front().x,l=q.front().y;
                    q.pop();
                    for(m=0;m<8;m++){
                        if(a[k+dir[m][0]][l+dir[m][1]]){
                            a[k+dir[m][0]][l+dir[m][1]]=0;
                            q.push({k+dir[m][0],l+dir[m][1]});
                        }
                    }
                }
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
4 5
10011
00001
01100
10011

4 4
0010
1010
0100
1111
*/
