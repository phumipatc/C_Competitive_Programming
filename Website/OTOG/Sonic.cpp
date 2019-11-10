/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[510];
int countt[30];
int main(){
    int q,n,ans;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",a+1);
        n = strlen(a+1);
        for(int i=1;i<=n;i++){
            a[i] = tolower(a[i]);
            countt[a[i]-'a'+1]++;
        }
        sort(countt+1,countt+27);
        ans = 0;
        for(int i=1;i<=26;i++)
            ans+=i*countt[i];
        printf("%d\n",ans);
        for(int i=1;i<=26;i++)
            countt[i] = 0;
    }
	return 0;
}