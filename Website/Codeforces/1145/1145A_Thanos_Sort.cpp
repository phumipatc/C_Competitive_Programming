/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[20];
int snap_the_finger(int l,int r){
    int ch = 1;
    for(int i=l;i<r;i++){
        if(a[i]>a[i+1]){
            ch = 0;
            break;
        }
    }
    if(ch)  return (r-l+1);
    int mid = (l+r)/2;
    return max(snap_the_finger(l,mid),snap_the_finger(mid+1,r));
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    printf("%d\n",snap_the_finger(1,n));
	return 0;
}
