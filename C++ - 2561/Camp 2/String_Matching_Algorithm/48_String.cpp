/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[2000200],b[2000200];
long long countt[30];
int main(){
    long long q,lena,lenb,ans;
    scanf("%lld",&q);
    while(q--){
        scanf(" %s %s",a+1,b+1);
        lena = strlen(a+1),lenb = strlen(b+1);
        ans = 0;
        for(long long i=1;i<=lenb-lena;i++)
            countt[b[i]-'a']++;
        for(long long i=1;i<=lena;i++){
            countt[b[lenb-lena+i]-'a']++;
            ans+=countt[a[i]-'a'];
            countt[b[i]-'a']--;
        }
        printf("%lld\n",ans);
        memset(countt,0,sizeof countt);
    }
	return 0;
}
