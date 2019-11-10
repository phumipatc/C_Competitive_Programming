/*
TASK: Plate Sort+
LANG: C
AUTHOR: PeaTT~
*/

#include <stdio.h>
int pos[300100];
int main(){
	int n,i,x,q;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		pos[0]=400000;
		for(i=0;i<n;i++){
			scanf("%d",&x);
			pos[x]=i;
		}
		for(i=n-1;i>=0;i--){
			if(pos[i]>pos[i+1]){
				printf("%d\n",i);
				break;
			}
		}
	}
    return 0;
}
