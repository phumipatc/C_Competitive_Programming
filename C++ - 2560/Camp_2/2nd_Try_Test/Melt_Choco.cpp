/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int r,l,ans;
int siz(int n){
    if(n<=1)    return 1;
    return (2*siz(n/2))+1;
}
void melt(int sizee,int L,int R){
    if(R<l) return ;
    if(L>r) return ;
    if(sizee<=1){
        ans+=sizee;
        return ;
    }
    int len=siz(sizee/2);
    melt(sizee/2,L,L+len-1);
    melt(sizee%2,L+len,L+len);
    melt(sizee/2,L+len+1,R);
}
int main()
{
    int n,len;
    scanf("%d %d %d",&n,&l,&r);
    len=siz(n);
    melt(n,1,len);
    printf("%d\n",ans);
    return 0;
}
