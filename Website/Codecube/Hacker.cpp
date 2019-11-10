/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > a[1000010];
int countt[1000010];
int main(){
    int n,m,temp,maxx,ans;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&temp);
            a[i].push_back(temp);
        }
        sort(a[i].begin(),a[i].end());
    }
    for(int i=0;i<m;i++){
        maxx = -1;
        for(int j=0;j<n;j++){
            if(a[j][i]>maxx){
                maxx = a[j][i];
                ans = j+1;
            }
        }
        countt[ans]++;
    }
    maxx = 0;
    for(int i=1;i<=n;i++){
        if(countt[i]>maxx){
            maxx = countt[i];
            ans = i;
        }
    }
    printf("%d\n",ans);
	return 0;
}
