/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100];
int main()
{
    int n,q,i,k;
    scanf("%d %d",&n,&q);
    for(k=1;k<n;k++){
        for(i=1;i<n;i++) {
            if(a[i]>a[i+1]){
                swap(a[i],a[i+1]);
            }
        }
    }
    return 0;
}
