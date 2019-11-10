/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[10100],ans[4] = {1,1,1};
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        if(a[i] == 13 && a[i+1] == 10)  ans[0]++;
        if(a[i] == 10)                  ans[1]++;
        if(a[i] == 13)                  ans[2]++;
    }
    printf("%d %d %d\n",ans[0],ans[1],ans[2]);
    return 0;
}
