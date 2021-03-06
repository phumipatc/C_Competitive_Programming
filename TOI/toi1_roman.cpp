/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: Implement
	Status	: Finished
*/
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using PII = pair<int ,int >;
using PLL = pair<long long ,long long >;
const int dir4[2][4] = {{1,-1,0,0},{0,0,1,-1}};
const int dir8[2][8] = {{-1,-1,-1,0,1,1,1,0},{-1,0,1,1,-1,0,1,-1}};
LL minN(vector<LL > a){
	LL minn = 1e18;
	for(auto x:a)
		minn = min(minn,x);
	return minn;
}
LL maxN(vector<LL > a){
	LL maxx = -1e18;
	for(auto x:a)
		maxx = max(maxx,x);
	return maxx;
}
int main(){
    int d,k,i = 0,v = 0,x = 0,l = 0,c = 0;
    scanf("%d",&d);
    for(int j=1;j<=d;j++){
        k=j;
		if(k>=300)  k-=300,c+=3;
        if(k>=200)  k-=200,c+=2;
        if(k>=100)  k-=100,c++;
        if(k>=90)   k-=90,c++,x++;
        if(k>=50)   k-=50,l++;
        if(k>=40)   k-=40,x++,l++;
        if(k>=30)   k-=30,x+=3;
        if(k>=20)   k-=20,x+=2;
        if(k>=10)   k-=10,x++;
        if(k>=9)    k-=9,i++,x++;
        if(k>=5)    k-=5,v++;
        if(k>=4)    k-=4,v++,i++;
        if(k>=3)    k-=3,i+=3;
        if(k>=2)    k-=2,i+=2;
        if(k>=1)    k--,i++;
    }
    printf("%d %d %d %d %d",i,v,x,l,c);
	return 0;
}
