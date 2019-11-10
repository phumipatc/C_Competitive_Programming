/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[200100],b[200100];
int main()
{
    int k,n,m,q,i=0,r,s,j=0;
    scanf("%d %d %d",&n,&m,&q);
    while(m--){
        scanf("%d %d",&r,&s);
        a[i++]=r;
        a[i++]=r+s;
    }
    sort(a,a+i);
    m=i;
    for(i=0;i<m;){
        for(k=i;k<m && a[ i]==a[k];k++);
        if((k-i)%2==1)
            b[j++]=a[i];
        i=k;
    }
    m=j;
    while(q--){
        scanf("%d",&r);
        if(r<b[0])          printf("%d\n",b[0]-1);
        else if(r>=b[m-1])  printf("%d\n",n-b[m-1]+1);
        else{
            s=upper_bound(b,b+m,r)-b;
            printf("%d\n",b[s]-b[s-1]);
        }
    }
    return 0;
}
/*
10 3 2
2 4
4 5
3 7
7
5
*/
