/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
map<int,int> mapp;
int qs[100100];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&qs[i]);
        qs[i]+=qs[i-1];
    }
    for(int i=1;i<n;i++){
        if(qs[i] == qs[n]-qs[i]){
            printf("%d\n",i);
            return 0;
        }
        mapp[qs[i]] = i;
    }
    for(int i=1;i<n;i++){
        if(qs[i]<qs[n]-qs[i])   continue;
        int want = (qs[i]-(qs[n]-qs[i]))/2;
        if(mapp[want]){
            printf("%d %d\n",mapp[want],i);
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
