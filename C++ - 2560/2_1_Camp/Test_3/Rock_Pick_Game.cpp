/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[110],mic[110][110];
int pick(int l,int r){
    if(l>r)         return 0;
    if(mic[l][r])   return mic[l][r];
    int maxx=-1;
    maxx=max(maxx,pick(l+1,r-1)+a[l]);
    maxx=max(maxx,pick(l+1,r-1)+a[r]);
    maxx=max(maxx,pick(l+2,r)+a[l]);
    maxx=max(maxx,pick(l,r-2)+a[r]);
    return mic[l][r]=maxx;
}
int main(){
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=2*n;i++)   scanf("%d",&a[i]);
    printf("%d\n",pick(1,2*n));
    return 0;
}
