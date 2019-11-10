/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[70][50];
int main(){
    int now,n,st,en,i,j;
    cin >> n;
    st = n;
    en = n+2;
    memset(a,45,sizeof a);
    //Up
    for(i=2;i<=n-2;i++){
        for(j=st;j<=en;j++)
            a[i][j] = '#';
        st--,en++;
    }
    for(i=n-1;i<=n+n-2;i++){
        for(j=st;j<=en;j++)
            a[i][j] = '#';
        st++,en--;
    }
    //Left
    for(i=n;i<=n+n-2;i++)
        for(j=2;j<=i-n+2;j++)
            a[i][j] = '#';
    now = 2;
    for(i=n+n-1;i<=n+n+n-4;i++){
        for(j=now;j<=n;j++)
            a[i][j] = '#';
        now++;
    }
    //Right
    now = (2*n);
    for(i=n;i<=n+n-2;i++){
        for(j=now;j<=(2*n);j++)
            a[i][j] = '#';
        now--;
    }
    now = (2*n);
    for(i=n+n-1;i<=n+n+n-4;i++){
        for(j=n+2;j<=now;j++)
            a[i][j] = '#';
        now--;
    }
    for(i=1;i<=(3*n)-3;i++){
        for(j=1;j<=(2*n)+1;j++)
            printf("%c ",a[i][j]);
        printf("\n");
    }
    return 0;
}
