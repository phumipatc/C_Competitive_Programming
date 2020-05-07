/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char a[52][110],st[110],en[110];
int l[52],r[52];
int main(){
	int q,n,ch;
	scanf("%d",&q);
	for(int t=1;t<=q;t++){
		scanf("%d",&n);
		memset(st,0,sizeof st);
		memset(en,0,sizeof en);
		ch = 1;
		for(int i=1;i<=n;i++){
			scanf(" %s",a[i]+1);
			if(!ch)	continue;
			int len = strlen(a[i]+1);
			l[i] = len+1;
			for(int j=1;j<=len;j++){
				if(a[i][j] == '*'){
					l[i] = j+1;
					break;
				}
				if(st[j] == 0){
					st[j] = a[i][j];
					continue;
				}
				if(st[j]!=0 && st[j]!=a[i][j]){
					ch = 0;
					break;
				}
			}
			r[i] = 0;
			for(int j=len;j>=1;j--){
				if(a[i][j] == '*'){
					r[i] = j-1;
					break;
				}
				if(en[len-j+1] == 0){
					en[len-j+1] = a[i][j];
					continue;
				}
				if(en[len-j+1]!=0 && en[len-j+1]!=a[i][j]){
					ch = 0;
					break;
				}
			}
		}
		printf("Case #%d: ",t);
		if(!ch)	printf("*\n");
		else{
			printf("%s",st+1);
			for(int i=1;i<=n;i++){
				for(int j=l[i];j<=r[i];j++){
					if(a[i][j] == '*')	continue;
					printf("%c",a[i][j]);
				}
			}
			int len = strlen(en+1);
			for(int i=1;i<=len/2;i++)
				swap(en[i],en[len-i+1]);
			printf("%s\n",en+1);
		}
	}
	return 0;
}