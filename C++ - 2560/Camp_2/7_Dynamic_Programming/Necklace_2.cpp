/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int max(int a,int b){
	return (a>=b)?a:b;
}
int min(int a,int b){
	return (a<=b)?a:b;
}
int left[200005][2], right[200005][2];	//[0] for red [1] for blue

int main(void){
	int n,i,ans=0;
	char tmp[100005],s[200005];
	scanf("%d %s",&n,tmp);
	strcpy(s,tmp);
	strcat(s,tmp);
	left[0][0] = left[0][1] = 0;
	for(i=1;i<=2*n;i++){
		if(s[i-1]=='r'){
			left[i][0] = left[i-1][0] + 1;
			left[i][1] = 0;
		}else if(s[i-1]=='b'){
			left[i][1] = left[i-1][1] + 1;
			left[i][0] = 0;
		}else{
			left[i][0] = left[i-1][0] + 1;
			left[i][1] = left[i-1][1] + 1;
		}
	}
	right[2*n][0] = right[2*n][1] = 0;
	for(i=2*n-1;i>=0;i--){
		if(s[i]=='r'){
			right[i][0] = right[i+1][0] + 1;
			right[i][1] = 0;
		}else if(s[i] == 'b'){
			right[i][1] = right[i+1][1] + 1;
			right[i][0] = 0;
		}else{
			right[i][0] = right[i+1][0] + 1;
			right[i][1] = right[i+1][1] + 1;
		}
	}
	for(i=0;i<2*n;i++)
       ans=max(ans, max(left[i][0],left[i][1])+max(right[i][0],right[i][1]));
	ans = min(ans,n);
	printf("%d\n",ans);
	return 0;
}
