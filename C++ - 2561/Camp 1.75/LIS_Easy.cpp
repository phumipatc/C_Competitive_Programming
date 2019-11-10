/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int LIS[1010],ans[1010];
vector<int > v[1010];
int main(){
    int n,maxx = 0,idx,num;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&num);
        idx = upper_bound(LIS,LIS+maxx,num)-LIS;
        if(idx>=1 && LIS[idx-1] == num) continue;
        if(idx == maxx)
            maxx++;
        LIS[idx] = num;
        v[idx].push_back(num);
    }
    printf("%d\n",maxx);
    num = v[maxx-1][0],idx = 0;
    ans[idx++] = num;
    for(int i=maxx-2;i>=0;i--){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]<num){
                num = v[i][j];
                ans[idx++] = num;
                break;
            }
        }
    }
    for(int i=idx-1;i>=0;i--)
        printf("%d ",ans[i]);
	return 0;
}
