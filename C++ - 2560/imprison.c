/*
TASK: Imprison
LANG: C
AUTHOR: PeaTT~
*/

#include <stdio.h>

int ab(int a){
	return (a>=0)?a:-a;
}

int main(){
	int n,m,p,a[30],b[30],ans[30],i,j,k,keep,diff,min;
	scanf("%d %d %d",&n,&m,&p);
	for(i=0;i<p;i++){
		scanf("%d %d",&a[i],&b[i]);
		ans[i]=0;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			keep=0,min=ab(a[0]-i)+ab(b[0]-j);
			for(k=1;k<p;k++){
				diff=ab(a[k]-i)+ab(b[k]-j);
				if(diff < min){
					min=diff,keep=k;
				}
			}
			ans[keep]++;
		}
	}
	for(i=0;i<p;i++)
		printf("%d\n",ans[i]);
    return 0;
}
