/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
int p[100100];
stack< PII> s;
int main()
{
    int l,q,i,height,idx,power;
    scanf("%d %d",&l,&q);
    for(i=0;i<l;i++){
        scanf("%d",&height);
        while(!s.empty() && s.top().first>height)   s.pop();
        if(s.empty())   power=0;
        else            power=max(height-s.top().first,s.top().second);
        p[i]=power;
        s.push(make_pair(height,power));
    }
    sort(p,p+l);
    while(q--){
        scanf("%d",&power);
        idx=upper_bound(p,p+l,power)-p;
        printf("%d\n",l-idx);
    }
    return 0;
}
