/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
map< int,int> mapp[6];
int a[20100];
bool cmp(int a,int b){
    int countt = 0;
    for(int i=1;i<=5;i++)
        if(mapp[i][a]>mapp[i][b])
            countt++;
    if(countt>2)    return false;
    else            return true;
}
int main(){
    int n,num;
    scanf("%d",&n);
    for(int i=1;i<=5;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[j]);
            mapp[i][a[j]]=j;
        }
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++)
        printf("%d\n",a[i]);
    return 0;
}
