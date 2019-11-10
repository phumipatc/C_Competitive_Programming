/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int type,i,j;
    bool operator<(const A&o)   const{
        if(type!=o.type)    return type < o.type;
        else if(j!=o.j) return j<o.j;
        else            return i<o.i;
    }
};
vector<A> ans;
A temp;
void play(int n,int imid,int jmid,int ihole,int jhole){
    int quad;
    if(ihole <imid && jhole>=jmid)  quad=1;
    else if(ihole<imid && jhole<jmid)   quad=0;
    else if(ihole>=imid && jhole<jmid)   quad=2;
    else if(ihole>=imid && jhole>=jmid) quad=3;
    temp.type=quad,temp.i=imid-1,temp.j=jmid-1;
    ans.push_back(temp);
    if(n<=2) return ;
    //Up Right
    if(quad==1) play(n/2,imid-n/4,jmid+n/4,ihole,jhole);
    else        play(n/2,imid-n/4,jmid+n/4,imid-1,jmid);

    if(quad==0) play(n/2,imid-n/4,jmid-n/4,ihole,jhole);
    else        play(n/2,imid-n/4,jmid-n/4,imid-1,jmid-1);

    if(quad==2) play(n/2,imid+n/4,jmid-n/4,ihole,jhole);
    else        play(n/2,imid+n/4,jmid-n/4,imid,jmid-1);

    if(quad==3) play(n/2,imid+n/4,jmid+n/4,ihole,jhole);
    else        play(n/2,imid+n/4,jmid+n/4,imid,jmid);
}
int n;
int main(){
    int jhole,ihole,n;
    scanf("%d %d %d",&n,&jhole,&ihole);
    play(n,n/2,n/2,ihole,jhole);
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d %d %d\n",ans[i].type,ans[i].j,ans[i].i);
    return 0;
}
