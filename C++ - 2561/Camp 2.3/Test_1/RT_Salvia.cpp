/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int word[30],countt;
int n,ans = 0;
char a[110];
void permute(int now,int state){
    if(now == n+1){
        // printf("%d %d %d\n",now,state,((1<<26)-1));
        if(state == ((1<<26)-1)) ans++;
        return ;
    }
    permute(now+1,state|word[now]);
    permute(now+1,state);
}
int main(){
    int q,len;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf(" %s",a+1);
            len = strlen(a+1);
            for(int j=1;j<=len;j++)
                word[i]|=1<<(a[j]-'a');
        }
        ans = 0;
        permute(1,0);
        printf("%d\n",ans);
        memset(word,0,sizeof word);
    }
	return 0;
}
/*
2
9
the
quick
brown
fox
jumps
over
a
lazy
dog
*/