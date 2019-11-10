/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[200100],b[200100];
int main(){
    int n,m,q,i,r,s,countt = 0,j;
    scanf("%d %d %d",&n,&m,&q);
    while(m--){
        scanf("%d %d",&r,&s);
        a[countt++] = r,a[countt++] = r+s;
    }
    sort(a,a+countt);
    for(i=0,r=0;i<countt;i=j){
        for(j=i+1;j<countt && a[i]==a[j];j++);
        if((j-i)%2 == 1){
            b[r++] = a[i];
        }
    }
    while(q--){
        scanf("%d",&s);
        if(s<b[0]){
            printf("%d\n",b[0]-1);
            continue;
        }else if(s>=b[r-1]){
            printf("%d\n",n-b[r-1]+1);
            continue;
        }
        j = upper_bound(b,b+r,s)-b;
        printf("%d\n",b[j]-b[j-1]);
    }
	return 0;
}
