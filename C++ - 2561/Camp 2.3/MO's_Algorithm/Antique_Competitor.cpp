/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int st,en,id;
    bool operator < (const A&o) const{
        return en<o.en;
    }
};
vector<A > v[320];
int a[100010],countt[100010],ans[100010];
int main(){
    int n,k,q,st,en,sqrtn;
    scanf("%d %d %d",&n,&k,&q);
    sqrtn = sqrt(100000);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=q;i++){
        scanf("%d %d",&st,&en);
        v[st/sqrtn].push_back({st,en,i});
    }
    for(int i=0;i<sqrtn;i++){
        if(v[i].empty())    continue;
        sort(v[i].begin(),v[i].end());
        memset(countt,0,sizeof countt);
        int res = 0,l,r;
        l = v[i][0].st,r = v[i][0].st;
        for(auto x:v[i]){
            while(r<=x.en){
                countt[a[r]]++;
                if(countt[a[r]] == k)
                    res++;
                r++;
            }
            while(l<x.st){
                countt[a[l]]--;
                if(countt[a[l]] == k-1)
                    res--;
                l++;
            }
            while(l>x.st){
                l--;
                countt[a[l]]++;
                if(countt[a[l]] == k)
                    res++;
            }
            ans[x.id] = res;
        }
    }
    for(int i=1;i<=q;i++)
        printf("%d\n",ans[i]);
    return 0;
}