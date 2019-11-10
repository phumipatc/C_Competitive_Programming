/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char ans[20];
int main(){
    int q,a,b,l,r,mid,n;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d",&a,&b,&n);
        l = a+1,r = b;
        while(1){
            mid = (l+r)/2;
            printf("%d\n",mid);
            fflush(stdout);
            scanf(" %s",ans);
            if(!strcmp(ans,"CORRECT"))          break;
            else if(!strcmp(ans,"TOO_SMALL"))   l = mid+1;
            else if(!strcmp(ans,"TOO_BIG"))     r = mid-1;
            else                                return 0;
        }
    }
	return 0;
}
