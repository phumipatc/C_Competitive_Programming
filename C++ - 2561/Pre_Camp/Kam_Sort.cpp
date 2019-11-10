/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1100],mark[1100];
void countt(int now){
    if(mark[now])   return;
    mark[now]=1;
    countt(a[now]);
}
int main(){
    int n,i,ans = 0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++){
        if(!mark[i] && a[i]!=i)
            countt(a[i]),ans++;
    }
    printf("%d\n",min(2,ans));
    return 0;
}
