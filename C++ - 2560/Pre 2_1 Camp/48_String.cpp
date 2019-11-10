/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[2000100],b[2000100];
long long countt[30];
int main()
{
    long long q,lena,lenb,ans,i,j,m,n;
    scanf("%lld",&q);
    while(q--){
        scanf(" %s %s",a+1,b+1);
        lena=strlen(a+1);
        lenb=strlen(b+1);
        m=(lenb-lena);
        for(i=1,ans=0,n=1;i<=lenb;i++){
            if(i<=lena) countt[a[i]-'a']++;
            ans+=countt[b[i]-'a'];
            if(i>m)     countt[a[n]-'a']--,n++;
        }
        printf("%lld\n",ans);
        memset(countt,0,sizeof countt);
    }
    return 0;
}
/*
1
abaab
aababacab

1
abba
aababbac
*/
