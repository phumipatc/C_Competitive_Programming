/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int pos[300010];
int main(){
    int q,n,temp;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        pos[0] = 1e9;
        for(int i=0;i<n;i++){
            scanf("%d",&temp);
            pos[temp] = i;
        }
        for(int i=n-1;i>=0;i--){
            if(pos[i]>pos[i+1]){
                printf("%d\n",i);
                break;
            }
        }
    }
	return 0;
}
