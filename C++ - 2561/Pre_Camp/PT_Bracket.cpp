/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[50010];
long long a[50010],b[50010];
priority_queue<long long > heap;
int main(){
    long long q,len,sum,ans;
    scanf("%lld",&q);
    while(q--){
        scanf(" %s",str+1);
        len = strlen(str+1),ans = sum = 0;
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        for(long long i=1;i<=len;i++)
            if(str[i] == '?')
                scanf("%lld %lld",&a[i],&b[i]);
        for(long long i=1;i<=len;i++){
            ans+=b[i];
            if(str[i] == '(')       sum++;
            else if(str[i] == ')')  sum--;
            else if(str[i] == '?'){
                sum--;
                heap.push(b[i]-a[i]);
            }
            if(sum == -1){
                if(heap.empty())    break;
                ans-=heap.top();
                heap.pop();
                sum = 1;
            }
        }
        if(sum!=0)  printf("-1\n");
        else        printf("%lld\n",ans);
        while(!heap.empty())    heap.pop();
    }
	return 0;
}
