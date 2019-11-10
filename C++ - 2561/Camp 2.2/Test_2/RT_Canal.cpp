/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int > pos;
int a[300010];
int main(){
    int n,k,l = 1e9,r = -1,mid,ch;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        l = min(l,a[i]);
        r = max(r,a[i]);
    }
    while(l<r){
        mid = (l+r+1)/2,ch = 1;
        pos.push_back(0);
        for(int i=1;i<=n;i++)
            if(a[i]>=mid)
                pos.push_back(i);
        pos.push_back(n+1);
        for(int i=0;i<pos.size()-1;i++){
            if(pos[i+1]-pos[i]>k){
                ch = 0;
                break;
            }
        }
        if(ch)  l = mid;
        else    r = mid-1;
        pos.clear();
    }
    printf("%d\n",l);
    return 0;
}
