/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[500002],n,m,r=1,start=0;
int findd(int num){
	if(r)
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
			j=findd(x);
			k=findd(y);
			temp=a[j];
			a[j]=a[k];
			a[k]=temp;
		}
		else if(c=='b'){
			scanf("%d %d",&x,&y);
			a[findd(x)]=y;
		}
		else if(c=='c'){
			scanf("%d",&x);
			start=findd(x);
			r^=1;
		}
		else if(c=='q'){
			scanf("%d",&x);
			printf("%d\n",a[findd(x)]);
		}
	}
	return 0;
}
