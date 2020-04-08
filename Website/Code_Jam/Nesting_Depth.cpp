/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char a[110];
int main(){
	int q;
	scanf("%d",&q);
	for(int x=1;x<=q;x++){
		scanf(" %s",a+1);
		int n = strlen(a+1);
		a[0] = a[n+1] = '0';
		printf("Case #%d: ",x);
		for(int i=1;i<=n;i++){
			if(a[i]>a[i-1]){
				int dif = a[i]-a[i-1];
				while(dif--)	printf("(");
			}
			printf("%c",a[i]);
			if(a[i]>a[i+1]){
				int dif = a[i]-a[i+1];
				while(dif--)	printf(")");
			}
		}
		printf("\n");
	}
	return 0;
}