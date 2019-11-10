/*
TASK: Spaceship
LANG: C
AUTHOR: PeaTT~
*/
#include <stdio.h>
#include <stdlib.h>

int at[20][5],have[20][5],n,min,mark[20],M;

void play(int x,int y,int z,int m,int k,int c,int sum){
	int i,nowx,nowy,nowz,mm,kk,cc,nowsum;
	for(i=0;i<M;i++){
		if(mark[i]!=7){
			mark[i]=7;
			mm=m+have[i][0],kk=k+have[i][1],cc=c+have[i][2];
			nowx=at[i][0],nowy=at[i][1],nowz=at[i][2];
			nowsum=sum+((x-nowx)*(x-nowx)+(y-nowy)*(y-nowy)+(z-nowz)*(z-nowz));
			if(mm>=n&&kk>=n&&cc>=n){
				if(nowsum<min)
					min=nowsum;
				mark[i]=0;
				continue;
			}
			play(nowx,nowy,nowz,mm,kk,cc,nowsum);
			mark[i]=0;
		}
	}
}

int main(){
	int x,y,z,i;
	scanf("%d %d %d %d %d",&n,&x,&y,&z,&M);
	for(i=0;i<M;i++){
		scanf("%d %d %d",&at[i][0],&at[i][1],&at[i][2]);
		scanf("%d %d %d",&have[i][0],&have[i][1],&have[i][2]);
	}
	min=2000000000;
	play(x,y,z,0,0,0,0);
	printf("%d\n",min);
	return 0;
}
