/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[110],b[110],c[110],temp;
int main(){
    int n,ca,cb,cc,maxx;
    scanf("%d",&n);
    ca = cb = cc = 0;
    for(int i=1;i<=n;i++){
        scanf(" %c",&temp);
        if(i%3 == 1)        a[i] = 'A';
        else if(i%3 == 2)   a[i] = 'B';
        else if(i%3 == 0)   a[i] = 'C';
        if(i%2 == 1)        b[i] = 'B';
        else if(i%4 == 0)   b[i] = 'C';
        else                b[i] = 'A';
        if(i%6 == 0 || i%6 == 5)        c[i] = 'B';
        else if(i%6 == 1 || i%6 == 2)   c[i] = 'C';
        else                            c[i] = 'A';
        if(a[i] == temp)    ca++;
        if(b[i] == temp)    cb++;
        if(c[i] == temp)    cc++;
    }
    maxx = max(ca,max(cb,cc));
    printf("%d\n",maxx);
    if(ca == maxx)  printf("Adrian\n");
    if(cb == maxx)  printf("Bruno\n");
    if(cc == maxx)  printf("Goran\n");
	return 0;
}
