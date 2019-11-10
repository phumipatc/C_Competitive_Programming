/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
//4*(n-1)+1
char a[410][410];
int dir[2][4] = {{0,1,0,-1},{1,0,-1,0}};
int main()
{
	int q,n,now,i,j,k;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		memset(a,'.',sizeof a);
		//preprocssing
		for(i=1;i<=4*(n-1)+1;i++)
			a[i][4*(n-1)+3] = '#';
		for(j=1;j<=4*(n-1)+1;j++)
			a[4*(n-1)+3][j] = '#';
		//Processing
		i = j = 1,k = 0;
		a[1][1] = '#';
		while(i!=n+n-1 || j!=n+n-1){
			// printf("%d %d\n",i,j);
			a[i][j] = '#';
			if(i+(2*dir[0][k])<0 || j+(2*dir[1][k])<0 || a[i+(2*dir[0][k])][j+(2*dir[1][k])] == '#')	k++,k%=4;
			i+=dir[0][k];
			j+=dir[1][k];
		}
		a[i][j] = '#';
		//Showing Output
		for(int i=1;i<=4*(n-1)+1;i++){
			for(int j=1;j<=4*(n-1)+1;j++){
				printf("%c",a[i][j]);
			}
			printf("\n");
		}
	}
    return 0;
}