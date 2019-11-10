/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int st,en,value;
    bool operator < (const A&o) const{
        if(en!=o.en)    return en<o.en;
        return st<o.st;
    }
};
vector<A> vect;
A temp;
int b[100100],mic[100100];
int main()
{
    int n,i,index;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %d",&temp.st,&temp.en,&temp.value);
        vect.push_back(temp);
    }
    sort(vect.begin(),vect.end());
    for(i=1;i<=n;i++)
        b[i]=vect[i-1].en;
    for(i=1;i<=n;i++){
        index=lower_bound(b+1,b+n+1,vect[i-1].st)-b-1;
        mic[i]=max(mic[i-1],mic[index]+vect[i-1].value);
    }
    printf("%d\n",mic[n]);
    return 0;
}
