/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: KMP
	Status	: Finished
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int ,int > PII;
typedef pair<long long ,long long > PLL;
int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
char a[1000010],b[1000010];
int KMP[1000010],jump[1000010];
char ans[1000010];
int main(){
	int q,n,m,i,j,pt;
	scanf("%d",&q);
	while(q--){
		scanf(" %s %s",a+1,b+1);
		n = strlen(a+1),m = strlen(b+1);
		for(i=2,j=0;i<=m;i++){
			while(j>0 && b[j+1]!=b[i])	j = KMP[j];
			if(b[j+1] == b[i])	j++;
			KMP[i] = j;
		}
		for(i=1,j=0,pt=0;i<=n;i++){
			while(j>0 && b[j+1]!=a[i])	j = KMP[j];
			if(b[j+1] == a[i])	j++;
			ans[++pt] = a[i];
			jump[pt] = j;
			if(j == m){
				pt-=m;
				j = jump[pt];
			}
		}
		ans[pt+1] = '\0';
		if(pt == 0)	printf("No COI Secret Code\n");
		else		printf("%s\n",ans+1);
	}
	return 0;
}