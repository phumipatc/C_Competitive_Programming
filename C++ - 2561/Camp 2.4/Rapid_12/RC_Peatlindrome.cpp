/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
    int q,n;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        int ans = 0,l = 1,r = n,sl = a[l],sr = a[r];
        while(l<r){
            // printf("%d %d %d %d\n",l,r,sl,sr);
            if(sl == sr){
                l++,r--;
                sl = a[l],sr = a[r];
            }else{
                if(sl>sr){
                    r--;
                    ans++;
                    sr+=a[r];
                }else{
                    l++;
                    ans++;
                    sl+=a[l];
                }
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}