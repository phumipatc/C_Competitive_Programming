/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include <bits/stdc++.h>
using namespace std;
int mic[1000100],a[1000100];
int main(){
    int n,i,last,now;
    scanf("%d %d",&n,&last);
    for(i=1;i<n;i++){
        scanf("%d",&now);
        a[i]=now-last;
        last = now;
    }
    mic[1]=a[1];
    for(i=2;i<n;i++)
        mic[i]=max(mic[i-1],mic[i-2]+a[i]);
    printf("%d\n",mic[n-1]);
    return 0;
}
