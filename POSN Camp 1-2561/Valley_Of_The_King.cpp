/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010];
vector<int > ans;
int main(){
    int q,n,countt;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        countt = 0;
        a[n+1] = 0;
        for(int i=1;i<=n;i++){
            if(a[i] == a[i+1]){
                i++;
                countt++;
                continue;
            }
            ans.push_back(a[i]);
        }
        printf("%d\n",countt);
        if(ans.size() == 0) printf("Empty");
        for(auto x:ans)
            printf("%d ",x);
        ans.clear();
        printf("\n");
    }
	return 0;
}