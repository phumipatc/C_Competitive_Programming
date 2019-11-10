/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010],qs[100010][320],ans[100010];
map<int ,int > mapp;
int main(){
    int n,q,l,r,an,cou = 1;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        mapp[a[i]]++;
        if(mapp[a[i]]>=a[i])    ans[cou++] = a[i],mapp[a[i]] = -1e9;
    }
    mapp.clear();
    for(int i=1;i<cou;i++)
        mapp[ans[i]] = i;
    for(int i=1;i<=n;i++){
        qs[i][mapp[a[i]]]++;
        for(int j=1;j<cou;j++){
            qs[i][j]+=qs[i-1][j];
        }
    }
    int countt;
    while(q--){
        scanf("%d %d",&l,&r);
        an = 0;
        for(int i=1;i<cou;i++){
            countt = qs[r][i]-qs[l-1][i];
            if(countt>=ans[i])   an++;
        }
        printf("%d\n",an);
    }
	return 0;
}
