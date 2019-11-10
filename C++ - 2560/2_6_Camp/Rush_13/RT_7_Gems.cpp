/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	long long i,j,t,g,w,gem;
};
A temp,now;
queue<A> heap;
char a[205][205];
int mark[205][205][130][7],d[5][2] = {{1,0},{0,1},{0,0},{-1,0},{0,-1}};
int main(){
	int n,m,tmp = 97;
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++){
		scanf(" %s",a[i]+1);
		for(int j=1; j<=m; j++){
			if(a[i][j] == 'S')
                temp.i = i,temp.j = j;
			if(a[i][j] == 'G')
                a[i][j] = tmp,tmp++;
		}
	}
	temp.t = 1,temp.g = temp.w = 0,temp.gem = 0;
	mark[temp.i][temp.j][temp.g][temp.t] = 1;
	heap.push(temp);
	while(!heap.empty()){
		now = heap.front();
		heap.pop();
		temp.g = now.g;
		if(now.gem == 7){
			printf("%lld\n",now.w);
			return 0;
		}
		for(int i=0; i<5; i++){
			temp.i = now.i+d[i][0];
			temp.j = now.j+d[i][1];
			temp.t = now.t+1;
			temp.gem = now.gem;
			temp.g = now.g;
			temp.w = now.w+1;
			if(a[temp.i][temp.j] >= 97 && a[temp.i][temp.j] <= 97+6)
				temp.g = (temp.g | (1<<(a[temp.i][temp.j]-97)));
			if(temp.g != now.g) temp.gem++;
			if(temp.t > 6)      temp.t = 1;
			if(temp.i < 1 || temp.j < 1 || temp.i > n || temp.j > m)    continue ;
			if(a[temp.i][temp.j] == '#')    continue ;
			if(mark[temp.i][temp.j][temp.g][temp.t])    continue ;
			if(a[temp.i][temp.j] >= '1' && a[temp.i][temp.j] <= '6' && temp.t != a[temp.i][temp.j] - '0' && temp.gem < a[temp.i][temp.j] -'0')
					continue;
			heap.push(temp);
			mark[temp.i][temp.j][temp.g][temp.t] = 1;
		}
	}
	printf("-1\n");
	return 0;
}
/*
2 6
S##G#G
GGGG5G
*/
