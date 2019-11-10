/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[5000010],mount[500010],ans[500010];
int main(){
    int n,k,idx = 0,idx2 = 1;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        if(a[i]>a[i-1] && a[i]>a[i+1]){
            mount[idx++] = -a[i];
        }
    }
    sort(mount,mount+idx);
    for(int i=0;i<idx;i++){
        if(idx2 == k+1)             break;
        if(mount[i] == mount[i+1])  continue;
        ans[idx2++] = mount[i];
    }
    if(idx2 == 1){
        printf("-1\n");
    }else if(idx2 == k+1){
        for(int i=1;i<idx2;i++){
            printf("%d\n",-ans[i]);
        }
    }else{
        for(int i=idx2-1;i>=1;i--){
            printf("%d\n",-ans[i]);
        }
    }
	return 0;
}
