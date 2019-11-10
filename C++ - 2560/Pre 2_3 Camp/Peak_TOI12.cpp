/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int hill[5000100],s[5000100];
priority_queue< int> heap;
vector< int> ans;
int main(){
    int n,k,idx=0;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&hill[i]);
    for(int i=1;i<=n;i++)
        if(hill[i]>hill[i-1] && hill[i]>hill[i+1])
            s[idx++]=hill[i];
    sort(s,s+idx);
    for(int i=0;i<idx;i++)
        if(s[i]!=s[i+1])
            heap.push(s[i]);
    if(heap.empty()){
        printf("-1\n");
        return 0;
    }
    if(heap.size()<k){
        while(!heap.empty()){
            ans.push_back(heap.top());
            heap.pop();
        }
        for(int i=ans.size()-1;i>=0;i--)
            printf("%d\n",ans[i]);
        return 0;
    }
    int countt=1;
    printf("%d\n",heap.top());
    heap.pop();
    while(!heap.empty()){

        if(countt==k)    break;
        countt++;
        printf("%d\n",heap.top());
        heap.pop();
    }
    return 0;
}
