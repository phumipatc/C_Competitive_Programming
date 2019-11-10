/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[5010],b[5010],LIS[5010];
map<int ,int > mapp;
int main(){
    int n,k,countt,maxx = 0,idx;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i] = a[i];
    }
    sort(b+1,b+n+1);
    countt = k;
    for(int i=1;i<=n;i++)
        mapp[b[i]] = (countt++)/k;
    for(int i=1;i<=n;i++){
        idx = upper_bound(LIS,LIS+maxx,mapp[a[i]])-LIS;
        if(idx == maxx) maxx++;
        LIS[idx] = mapp[a[i]];
    }
    printf("%d\n",n-maxx);
	return 0;
}
