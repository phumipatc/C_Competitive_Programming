/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100],b[1000100];
int main()
{
    int q,n,x,y,z,current_milk,i,j,maxx;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d %d",&n,&x,&y,&z);
        for(i=0;i<n;i++){
            scanf("%d %d",&a[i],&b[i]);
        }
        sort(a,a+n);
        sort(b,b+n);
        a[n]=b[n]=1e9;
        current_milk=n*x;
        i=0,j=0,maxx=-1;
        while(i<n || j<n){
//            printf("%d %d %d\n",a[i],b[j],current_milk);
            if(a[i]<=b[j]){
                current_milk+=y-x;
                i++;
            }else{
                current_milk+=z-y;
                j++;
            }
            maxx=max(maxx,current_milk);
        }
        printf("%d\n",maxx);
    }
    return 0;
}
/*
1
4 7 9 6
5 8
3 4
13 20
7 10
*/
