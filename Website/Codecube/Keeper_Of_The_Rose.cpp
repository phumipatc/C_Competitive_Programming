/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int last[1000010],day[1000010];
int main(){
    int n,m,num,countt = 0;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&day[i]);
    for(int i=1;i<=m;i++){
        scanf("%d",&num);
        if(i-last[num]>=day[num]) countt++,last[num] = i;
    }
    printf("%d\n",countt);
    return 0;
}
