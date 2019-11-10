/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int idx,v;
};
deque< A> deq;
int a[1100][1100],seat[1100];
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)  seat[i]++;
        }
        seat[i]+=seat[i-1];
    }
    int countt;
    for(int i=n;i>=1;i--){
        countt=0;
        for(int j=1;j<=m;j++){
            while(deq.front().idx<=j-k){
                if(deq.front().v==1)    countt--;
                deq.pop_front();
            }
            if(a[i][j]==1)  countt++;
            deq.push_back({j,a[i][j]});
            if(j>=k && seat[n]-seat[i]>=countt){
                printf("%d\n",i);
                return 0;
            }
        }
        while(!deq.empty()) deq.pop_back();
    }
    return 0;
}
