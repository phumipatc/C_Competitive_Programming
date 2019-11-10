/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
deque< int> q;
int a[100100],idx[100100];
int main(){
    int n,i,num;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        idx[a[i]]=i;
    }
    return 0;
}
