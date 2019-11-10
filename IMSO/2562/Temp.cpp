/*
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mark[22],anss[7];
int countt = 0;
void permute(int state,int sum,int last){
	if(state == 6)	return ;
	if(sum>20)		return ;
	if(sum == 20){
		//printf("%d: ",countt);
		countt++;
		for(int i=1;i<state;i++)
			printf("%d ",anss[i]);
		printf("\n");
		return ;
	}
	for(int i=last+1;i<=20;i++){
		if(mark[i])	continue;
		mark[i] = 1;
		anss[state] = i;
		permute(state+1,sum+i,i);
		mark[i] = 0;
	}
}
int main(){
	freopen("temp.txt","w",stdout);
	printf("%d\n",countt);
	permute(1,0,0);
	printf("%d\n",countt);
	return 0;
}
