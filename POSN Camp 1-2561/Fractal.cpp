/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int countt[1030];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=(1<<n)-1;i++){
        for(int j=1;j<=(i&-i)*countt[(i&-i)];j++)
            printf("-");
        for(int j=1;j<=(i&-i);j++)
            printf("*");
        for(int j=(i&-i)*countt[(i&-i)]+(i&-i);j<=(1<<(n-1))-1;j++)
            printf("-");
        countt[(i&-i)]++;
        printf("\n");
    }
    return 0;
}