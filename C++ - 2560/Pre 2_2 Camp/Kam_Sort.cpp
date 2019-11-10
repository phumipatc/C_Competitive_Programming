/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int num[1100],mark[1100];
void countt(int now){
    if(mark[now])   return;
    mark[now]=1;
    countt(num[now]);
}
int main(){
    int n,i,round=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&num[i]);
    for(i=1;i<=n;i++){
        if(!mark[i] && num[i]!=i)
            countt(num[i]),round++;
    }
    if(round>=2)    printf("2\n");
    else            printf("%d\n",round);
    return 0;
}
