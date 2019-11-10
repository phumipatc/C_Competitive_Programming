/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[100010][12];
int countt[30][30];
int main(){
    int n,len,ans = 0;
    scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf(" %s",str[i]+1);
		len = strlen(str[i]+1);
		countt[str[i][1]-'A'][str[i][len]-'A']++;
	}
	for(int i=1;i<=n;i++){
		countt[str[i][1]-'A'][str[i][len]-'A']--;
		for(int j=0;j<26;j++){
			for(int k=0;k<26;k++){
				ans+=(countt[str[i][1]-'A'][j])*(countt[str[i][len]-'A'][k])*(countt[j][k]);
			}
		}
		countt[str[i][1]-'A'][str[i][len]-'A']--;
	}
	printf("%d\n",ans);
	return 0;
}
