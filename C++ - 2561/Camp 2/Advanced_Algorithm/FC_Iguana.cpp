/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int idx,v;
    bool operator < (const A&o) const{
        if(idx!=o.idx)  return idx<o.idx;
        else            return v<o.v;
    }
};
A line[200100];
int main(){
    int n,m,st,en,countt = 0,want,ans = 0,i,j,sum = 0;
    char temp;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf("%d %d",&st,&en);
        line[countt].idx = st,line[countt++].v = 1;
        line[countt].idx = en+1,line[countt++].v = -1;
    }
    scanf(" %c",&temp);
    if(temp == 'R')         want = 0;
    else if(temp == 'G')    want = 1;
    else                    want = 2;
    line[countt].idx = 1,line[countt++].v = 0;
    line[countt].idx = n+1,line[countt++].v = 0;
    sort(line,line+countt);
    for(i=0;i<countt-1;i++){
        sum+=line[i].v;
        ans+=(line[i+1].idx-line[i].idx)*((want-(sum%3)+3)%3);
    }
    printf("%d\n",ans);
	return 0;
}
