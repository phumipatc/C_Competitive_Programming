/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[1100];
int mark[1100][26];
int main(){
	// freopen("0_in.txt","r",stdin);
	// freopen("0_out.txt","w",stdout);
	int n,ch = 1;
	scanf("%d %s",&n,str+1);
	for(int i=1;i<=n;i++){
		for(int j=0;j<26;j++)	mark[i][j] = mark[i-1][j];
		mark[i][str[i]-'a']++;
		for(int j=1;j<i;j++){
			for(int k=0;k<26;k++){
				if(mark[i][k]-mark[j-1][k]>(i-j+1)/2){
					ch = 0;
					break;
				}
			}
			if(ch){
				printf("YES\n");
				for(int k=j;k<=i;k++)
					printf("%c",str[k]);
				return 0;
			}
			ch = 1;
		}
	}
	printf("NO\n");
	return 0;
}
