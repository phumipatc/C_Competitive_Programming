/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000010],mark[1000010];
int main(){
    int n,countt = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        if(mark[a[i]+1])    mark[a[i]+1]--;
        else                countt++;
        mark[a[i]]++;
    }
    printf("%d\n",countt);
    return 0;
}
