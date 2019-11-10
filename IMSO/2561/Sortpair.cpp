/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[100100];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d",&a[i].first,&a[i].second);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        printf("%d %d\n",a[i].first,a[i].second);
    return 0;
}
