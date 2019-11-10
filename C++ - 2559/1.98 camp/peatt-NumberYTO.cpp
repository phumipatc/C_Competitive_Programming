/*
TASK: number
LANG: C
AUTHOR: PeaTT~
*/
#include <stdio.h>

int a[500002],n,m,right=1,start=0;

int find(int num){
	if(right)
		return (num+start-1)%n;
	else
		return (n+start-num+1)%n;
}

int main(){
	int i,j,k,x,y,temp;
	char c;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<m;i++){
		scanf(" %c ",&c);
		if(c=='a'){
			scanf("%d %d",&x,&y);
			j=find(x);
			k=find(y);
			temp=a[j];
			a[j]=a[k];
			a[k]=temp;
		}
		else if(c=='b'){
			scanf("%d %d",&x,&y);
			a[find(x)]=y;
		}
		else if(c=='c'){
			scanf("%d",&x);
			start=find(x);
			right^=1;
		}
		else if(c=='q'){
			scanf("%d",&x);
			printf("%d\n",a[find(x)]);
		}
	}
	return 0;
}
