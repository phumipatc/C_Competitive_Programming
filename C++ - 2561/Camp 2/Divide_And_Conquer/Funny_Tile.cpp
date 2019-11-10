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
void divide(int n,int midi,int midj,int hi,int hj){
    int quad;
    if(hi <midi && hj>=midj)        quad=1;
    else if(hi<midi && hj<midj)     quad=0;
    else if(hi>=midi && hj<midj)    quad=2;
    else if(hi>=midi && hj>=midj)   quad=3;
    ans.push_back({quad,midi-1,midj-1});
    if(n<=2) return ;

    if(quad == 0)   divide(n/2,midi-n/4,midj-n/4,hi,hj);
    else            divide(n/2,midi-n/4,midj-n/4,midi-1,midj-1);

    if(quad == 1)   divide(n/2,midi-n/4,midj+n/4,hi,hj);
    else            divide(n/2,midi-n/4,midj+n/4,midi-1,midj);

    if(quad == 2)   divide(n/2,midi+n/4,midj-n/4,hi,hj);
    else            divide(n/2,midi+n/4,midj-n/4,midi,midj-1);

    if(quad == 3)   divide(n/2,midi+n/4,midj+n/4,hi,hj);
    else            divide(n/2,midi+n/4,midj+n/4,midi,midj);
}
int n;
int main(){
    int hj,hi,n;
    scanf("%d %d %d",&n,&hj,&hi);
    divide(n,n/2,n/2,hi,hj);
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();i++)
        printf("%d %d %d\n",ans[i].type,ans[i].j,ans[i].i);
    return 0;
}
