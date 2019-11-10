/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
pair<int ,int > a[100010];
int LIS[100010];
int main(){
    int q,maxx,n,idx;
    scanf("%d",&q);
    while(q--){
        maxx = 0;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d %d",&a[i].first,&a[i].second);
            a[i].first*=-1;
        }
        sort(a,a+n);
        for(int i=0;i<n;i++){
            idx = upper_bound(LIS,LIS+maxx,a[i].second)-LIS;
            if(idx == maxx) maxx++;
            LIS[idx] = a[i].second;
        }
        printf("%d\n",maxx);
        memset(LIS,0,sizeof LIS);
    }
	return 0;
}
