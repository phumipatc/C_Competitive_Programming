/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int st,en,num;
    bool operator < (const A&o) const{
        return en<o.en;
    }
};
A temp;
vector< A> v[400];
int sqrtn,a[100010],ans[100010],countt[100010];
int main(){
    int n,k,q;
    scanf("%d %d %d",&n,&k,&q);
    sqrtn=sqrt(100000);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=q;i++){
        scanf("%d %d",&temp.st,&temp.en);
        temp.num=i;
        v[temp.st/sqrtn].push_back(temp);
    }
    for(int i=0;i<=sqrtn;i++){
        sort(v[i].begin(),v[i].end());
        for(int j=1;j<=n;j++)
            countt[j]=0;
        int res=0,l,r;
        if(v[i].size()>0){
            l=v[i][0].st,r=v[i][0].st;
            for(int j=0;j<v[i].size();j++){
                while(r<=v[i][j].en){
                    countt[a[r]]++;
                    if(countt[a[r]]==k)
                        res++;
                    r++;
                }
                while(l<v[i][j].st){
                    countt[a[l]]--;
                    if(countt[a[l]]==k-1)
                        res--;
                    l++;
                }
                while(l>v[i][j].st){
                    l--;
                    countt[a[l]]++;
                    if(countt[a[l]]==k)
                        res++;
                }
                ans[v[i][j].num]=res;
            }
        }
    }
    for(int i=1;i<=q;i++)
        printf("%d\n",ans[i]);
    return 0;
}
