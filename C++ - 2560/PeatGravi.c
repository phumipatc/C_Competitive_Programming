/*
TASK: Peatt Gravity
LANG: C++
AUTHOR: PeaTT~
*/
#include <stdio.h>
#include <math.h>
#include <time.h>

struct pt
{
	double i,j;
	double x;	
};

pt x[20];
int chk[20];
double r,c,ans=1000000000;
double table[20][20];
int k;

void play(int xx,double t){
	int i;
	double tmp;
	tmp=table[xx][15]+t;
	if(ans>tmp)
		ans=tmp;
	for(i=1;i<=k;i++)
	{
		if(chk[i]==0)
		{
			tmp=table[xx][i]+t;
			tmp=tmp-x[i].x;
			chk[i]=1;
			play(i,tmp);
			chk[i]=0;
		}
	}
	return ;
}

int main(){
	int i,j;
	double tmp;
	scanf("%lf %lf %d",&r,&c,&k);
	r--;
	c--;
	for(i=0;i<k;i++)
		chk[i]=0;
	for(i=1;i<=k;i++)
		scanf("%lf %lf %lf",&x[i].i,&x[i].j,&x[i].x);
	for(i=0;i<=k;i++)
	{
		tmp=(r-x[i].i)*(r-x[i].i)+(c-x[i].j)*(c-x[i].j);
		tmp=sqrt(tmp);
		tmp=ceil(tmp);
		table[i][15]=tmp;
		for(j=0;j<=k;j++)
		{
			tmp=(x[i].i-x[j].i)*(x[i].i-x[j].i)+(x[i].j-x[j].j)*(x[i].j-x[j].j);
			tmp=sqrt(tmp);
			tmp=ceil(tmp);
			table[i][j]=tmp;
		}
	}
	tmp=(r)*(r)+(c)*(c);
	tmp=sqrt(tmp);
	tmp=ceil(tmp);
	ans=tmp;
	table[i][15]=tmp;
	play(0,0);
	printf("%.0lf\n",ans);
	return 0;
}
