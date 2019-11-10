/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[5000010],b[10000010];
int KMP[5000010];
int main(){
    int n,j = 0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf(" %c",&a[i]);
        b[i] = b[i+n] = a[i];
    }
    for(int i=2;i<=n;i++){
        while(j>0 && a[j+1]!=a[i])  j = KMP[j];
        if(a[i] == a[j+1])  j++;
        KMP[i] = j;
        // printf("%d ",KMP[i]);
    }
    j = 0;
    for(int i=2;i<=2*n;i++){
        while(j>0 && a[j+1]!=b[i])  j = KMP[j];
        if(b[i] == a[j+1])  j++;
        if(j == n){
            printf("%d\n",i-n);
            break;
        }
    }
	return 0;
}
