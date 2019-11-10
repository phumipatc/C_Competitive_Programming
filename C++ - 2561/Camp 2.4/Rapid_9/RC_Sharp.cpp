/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[510],choice[510][30],ans[510];
long long mul[510];
long long idx = 1,k,a,m,n;
void permute(long long now,long long sum){
    if(now == m+1){
        for(long long i=1,id=1;i<=n;i++){
            if(str[i] == '#')   printf("%c",ans[id++]);
            else                printf("%c",str[i]);
        }
        return ;
    }
    for(long long i=k;i>=1;i--){
        if(sum+(i-1)*mul[now+1]<=a){
            ans[idx++] = choice[now][i];
            permute(now+1,sum+(i-1)*mul[now+1]);
            break;
        }
    }
}
int main(){
    long long all = 1;
    scanf("%lld %lld %lld %lld %s",&n,&m,&k,&a,str+1);
    for(long long i=1;i<=m;i++){
        scanf(" %s",choice[i]+1);
        sort(choice[i]+1,choice[i]+k+1);
        // printf("%s\n",choice[i]+1);
    }
    a--;
    mul[m+1] = 1;
    for(long long i=m;i>=1;i--)
        mul[i] = min(mul[i+1]*k,(long long )2e9);
    permute(1,0);
	return 0;
}
/*
9 2 3 7
peat#hi#y
sol
nuz
*/