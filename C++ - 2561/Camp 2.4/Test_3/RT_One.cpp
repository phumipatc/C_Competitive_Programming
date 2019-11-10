/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int GCD(int a,int b,int *x,int *y){
    if(a == 0){
        *x = 0,*y = 1;
        return b;
    }
    int xt,yt;
    int temp = GCD(b%a,a,&xt,&yt);
    *x = yt - (b/a) * xt;
    *y = xt;
    return temp;
}
int main(){
    int q,a,b,x,y;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&a,&b);
        if(GCD(a,b,&x,&y)!=1){
            printf("NO SOLUTION\n");
            continue;
        }
        printf("%d\n",abs(x)+abs(y));
    }
	return 0;
}