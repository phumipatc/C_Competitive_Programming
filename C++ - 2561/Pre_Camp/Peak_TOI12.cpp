/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[5000010],b[5000010];
int main(){
    int n,k,idx = 1,idx2 = 1;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        if(a[i]>a[i-1] && a[i]>a[i+1])
            b[idx++] = a[i];
    }
    sort(b+1,b+idx);
    for(int i=1;i<idx;i++){
        if(b[i] == b[i+1])  continue;
        b[idx2++] = b[i];
    }
    b[idx2] = 0;
    idx2--;
    if(idx2 == 0){
        printf("-1\n");
    }else if(idx2<k){
        for(int i=1;i<=idx2;i++)
            printf("%d\n",b[i]);
    }else{
        idx = idx2;
        while(k--){
            printf("%d\n",b[idx]);
            idx--;
        }
    }
	return 0;
}
