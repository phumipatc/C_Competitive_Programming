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
    int n,i,j = 0;
    scanf("%d %s",&n,a+1);
    strcpy(b+1,a+1),strcat(b+1,a+1);
    for(i=2;i<=n;i++){
        while(j>0 && a[i]!=a[j+1])  j = KMP[j];
        if(a[i] == a[j+1])  j++;
        KMP[i] = j;
    }
    j = 0;
    for(i=2;i<=2*n;i++){
        while(j>0 && b[i]!=a[j+1])  j = KMP[j];
        if(b[i] == a[j+1])  j++;
        if(j == n){
            printf("%d\n",i-j);
            break;
        }
    }
	return 0;
}
