/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > lv[12];
int a[1030];
void dfs(int l,int r,int state){
    if(l == r){
        lv[state].push_back(a[l]);
        return ;
    }
    int mid = (l+r)/2;
    // printf("%d %d %d %d\n",l,r,mid,state);
    lv[state].push_back(a[mid]);
    dfs(l,mid-1,state+1);
    dfs(mid+1,r,state+1);
}
int main(){
    int k;
    scanf("%d",&k);
    for(int i=1;i<(1<<k);i++)
        scanf("%d",&a[i]);
    dfs(1,(1<<k)-1,1);
    for(int i=1;i<=k;i++){
        for(auto x:lv[i])
            printf("%d ",x);
        printf("\n");
    }
	return 0;
}