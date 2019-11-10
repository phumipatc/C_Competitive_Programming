/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100],b[1000100],c[1000100],m[1000100];
int main(){
    int q,n,i,j,k,maxx,x;
    scanf("%d",&q);
    while(q--){
        maxx=0;
        x=-1;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d",&k);
            a[k]=i;
        }
        for(i=1;i<=n;i++){
            scanf("%d",&k);
            b[k]=i;
        }
        for(i=1;i<=n;i++){
            c[i]=b[i]-a[i];
            if(c[i]<0)
                c[i]+=n;
            m[c[i]]++;
        }
        for(i=0;i<=n;i++){
            if(maxx<m[i]){
                maxx=m[i];
                x=i;
            }
        }
        printf("%d %d\n",maxx,x);
        memset(m,0,sizeof m);
    }
    return 0;
}
/*
2
4
1 3 4 2
3 4 1 2

10
9 10 6 4 3 2 7 1 5 8
4 3 9 1 5 10 6 7 8 2
*/
