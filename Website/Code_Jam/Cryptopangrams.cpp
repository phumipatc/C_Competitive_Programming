/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[110];
int a[110],ans[110],comp[110];
map<int ,int > mapp;
int gcd(int a,int b){
    if(a%b == 0)    return b;
    else            return gcd(b,a%b);
}
int main(){
    int q,n,GCD,now;
    scanf("%d",&q);
    for(int x=1;x<=q;x++){
        scanf("%s %d",str+1,&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        now = 1;
        while(a[now] == a[now+1])   now++;
        GCD = gcd(a[now],a[now+1]);
        ans[now] = a[now]/GCD;
        ans[now+1] = GCD;
        ans[now+2] = a[now+1]/GCD;
        for(int i=now-1;i>=1;i--)
            ans[i] = a[i]/ans[i+1];
        for(int i=now+3;i<=n+1;i++)
            ans[i] = a[i-1]/ans[i-1];
        for(int i=1;i<=n+1;i++)
            comp[i] = ans[i];
        sort(comp+1,comp+n+2);
        now = 'A';
        for(int i=1;i<=n+1;i++){
            if(comp[i] == comp[i+1])    continue;
            mapp[comp[i]] = now;
            now++;
        }
        printf("Case #%d: ",x);
        for(int i=1;i<=n+1;i++)
            printf("%c",mapp[ans[i]]);
        printf("\n");
        mapp.clear();
        memset(a,0,sizeof a);
        memset(ans,0,sizeof ans);
        memset(comp,0,sizeof comp);
    }
	return 0;
}
