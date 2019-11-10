/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int idx,value;
    bool operator <(const A&o) const{
        if(idx!=o.idx)  return idx<o.idx;
        else            return value<o.value;
    }
};
vector< A> line;
int main(){
    int n,m,a,b,color,ans=0,sum=0,num;
    char col;
    scanf("%d %d",&n,&m);
    line.push_back({1,0});
    line.push_back({n+1,0});
    for(int i=1;i<=m;i++){
        scanf("%d %d",&a,&b);
        line.push_back({a,1});
        line.push_back({b+1,-1});
    }
    sort(line.begin(),line.end());
    scanf(" %c",&col);
    if(col=='R')        color=0;
    else if(col=='G')   color=1;
    else                color=2;
    for(int i=0;i<line.size()-1;i++){
        sum+=line[i].value;
        num=line[i+1].idx-line[i].idx;
        ans+=((color-(sum%3)+3)%3)*num;
    }
    printf("%d\n",ans);
    return 0;
}
