/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
    int q,h,n,countt;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&h,&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        countt = 0;
        a[n+1] = 0;
        for(int i=1;i<n;i++){
            if(a[i] == 2)   break;
            if(a[i] == a[i+1]+1){
                if(a[i+2]+1 == a[i+1])  i++;
                else                    a[i+1] = a[i+2]+1,countt++;
            }else{
                a[i] = a[i+1]+1;
                if(a[i+2]+1 == a[i+1])  i++;
                else                    a[i+1] = a[i+2]+1,countt++;
            }
        }
        printf("%d\n",countt);
    }
	return 0;
}