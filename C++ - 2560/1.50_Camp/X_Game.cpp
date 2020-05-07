/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[10][10],ans=1e9;
void play(int i,int j,int state){
	int ii,jj,t=a[1][1],ch=1;
	for(ii=1;ii<=4;ii++)
		for(jj=1;jj<=4;jj++)
			if(a[ii][jj]!=t)
				ch=0;
	if(ch){
		if(state<ans){
			ans=state;
		}
		return ;
	}
	if(i<1||j<1||i>4||j>4)	return ;
	if(j==4)	play(i+1,1,state);
	else		play(i,j+1,state);
	a[i][j]=(a[i][j]+1)%2;
	a[i+1][j]=(a[i+1][j]+1)%2;
	a[i][j+1]=(a[i][j+1]+1)%2;
	a[i-1][j]=(a[i-1][j]+1)%2;
	a[i][j-1]=(a[i][j-1]+1)%2;
	if(j==4)	play(i+1,1,state+1);
	else		play(i,j+1,state+1);
	a[i][j]=(a[i][j]+1)%2;
	a[i+1][j]=(a[i+1][j]+1)%2;
	a[i][j+1]=(a[i][j+1]+1)%2;
	a[i-1][j]=(a[i-1][j]+1)%2;
	a[i][j-1]=(a[i][j-1]+1)%2;
}
int main(){
	int i,j;
	char c;
	for(i=1;i<=4;i++){
		for(j=1;j<=4;j++){
			scanf(" %c",&c);
			a[i][j]=(c=='b')?1:0;
		}
	}
	play(1,1,0);
	printf((ans==1e9)?"Impossible\n":"%d\n",ans);
	return 0;
}

