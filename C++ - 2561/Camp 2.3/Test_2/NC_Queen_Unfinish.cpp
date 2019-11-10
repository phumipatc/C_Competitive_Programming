/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
queue<pair<int ,int > > que;
pair<int ,int > p[8],now;
char a[10][10];
int dir[2][4] = {{-1,1,0,0},{0,0,1,-1}};
int dis[10][10],mark[8],ans[8],num[10][10];
int minn = 1e9;
void permute(int state){
	if(state == 5){
		int sum = 0;
		ans[5] = 5;
		
		return ;
	}
	for(int i=1;i<=4;i++){
		if(mark[i])	continue;
		mark[i] = 1;
		ans[state] = i;
		permute(state+1);
		mark[i] = 0;
	}
}
int main(){
    int q,countt,ni,nj;
    scanf("%d",&q);
    while(q--){
        countt = 1;
		memset(num,-1,sizeof num);
        for(int i=1;i<=8;i++){
            scanf(" %s",a[i]+1);
			for(int j=1;j<=8;j++){
				if(a[i][j] == 'Q')	num[i][j] = 0,p[0] = {i,j};
				if(a[i][j] == 'x')	num[i][j] = countt,p[countt++] = {i,j};
				if(a[i][j] == 'k')	num[i][j] = 5,p[5] = {i,j};
			}
		}
    }
	permute(1);
	if(minn == 1e9)	printf("-1\n");
	else			printf("%d\n",minn);
	return 0;
}
/*
1
........
....k...
.x.X..x.
....K.Q.
..x...x.
X.......
.......X
........
*/