/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[110];
int a[30],countt,n;
void permute(int state,int val){
    if(state==n){
        if(val==(1<<26)-1)
            countt++;
        return ;
    }
    permute(state+1,val);
    permute(state+1,val|a[state]);
}
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        countt=0;
        memset(a,0,sizeof a);
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf(" %s",str);
            int len=strlen(str);
            for(int j=0;j<len;j++)
                a[i]|=1<<(str[j]-'a');
        }
        permute(0,0);
        printf("%d\n",countt);
    }
    return 0;
}
