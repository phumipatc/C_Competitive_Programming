/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
#define MOD 400009
using namespace std;
char a[10010],hashh[55][MOD+10][55],ans[55];
int main(){
	int n,sum,len,jump;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf(" %s",a+1);
		sum = 0,len = strlen(a+1);
		for(int i=1;i<=len;i++)
			sum = ((sum*29)+a[i]-'a')%MOD;
		jump = 1;
		while(hashh[len][(sum+jump)%MOD][0]!=0)
			jump<<=1;
		strcpy(hashh[len][(sum+jump)%MOD],a+1);
	}
	int q,countt;
	scanf("%d",&q);
	while(q--){
		scanf(" %s",a+1);
		len = strlen(a+1);
		countt = 0;
		for(int i=1;i<=len;i++){
			sum = 0;
			for(int j=i;j<=len && j-i+1<=50;j++){
				sum = ((sum*29)+a[j]-'a')%MOD;
				jump = 1;
				while(hashh[j-i+1][(sum+jump)%MOD][0]!=0){
					if(!strncmp(hashh[j-i+1][(sum+jump)%MOD],a+i,j-i+1)){
						countt++;
						strcpy(ans,hashh[j-i+1][(sum+jump)%MOD]);
						if(countt == 2)	goto next;
					}
					jump<<=1;
				}
			}
		}
		next:;
		if(countt == 0)			printf("NO\n");
		else if(countt == 1)	printf("%s\n",ans);
		else					printf("AMBIGUOUS\n");
	}
	return 0;
}
