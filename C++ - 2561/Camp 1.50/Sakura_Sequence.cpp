/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    char str[20];
    long long v,len;
};
A now;
long long a[11000000];
char c[20];
queue< A> que;
int main(){
    long long countt = 0,len,v,sum,idx,q;
    for(long long i=0;i<26;i++){
        now.str[0] = 'a'+i;
        now.str[1] = NULL;
        now.v = i+1;
        now.len = 1;
        que.push(now);
    }
    while(!que.empty()){
        now = que.front();
        que.pop();
        strcpy(c,now.str);
        len = now.len;
        v = now.v;
        if(len == 11)  break;
        a[countt++] = now.v;
        for(long long i=c[len-1]-'a'+1;i<=25;i++){
            now.str[len] = 'a'+i;
            now.v = (v*27)+i+1;
            now.str[len+1] = NULL;
            now.len = len+1;
            que.push(now);
        }
    }
    scanf("%lld",&q);
    while(q--){
        scanf(" %s",c);
        len = strlen(c);
        sum = 0;
        for(long long i=0;i<len;i++)
            sum*=27,sum+=c[i]-'a'+1;
        idx = lower_bound(a,a+countt,sum)-a;
        if(a[idx] == sum)   printf("%lld\n",idx+1);
        else                printf("0\n");
    }
	return 0;
}
