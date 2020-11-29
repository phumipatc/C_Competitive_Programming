/*
	Author	: Phumipat C. [MAGCARI]
	School	: RYW
	Language: C++
	Algo	: DP
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
bool mark[110];
int nugget[3] = {6,9,20};
int main(){
    int n,countt = 0;
    scanf("%d",&n);
    mark[0] = true;
    for(int i=0;i<3;i++)
        for(int j=nugget[i];j<=n;j++)
            if(mark[j-nugget[i]])
                mark[j] = true;
	bool ch = 0;
    for(int i=1;i<=n;i++)
        if(mark[i])
            printf("%d\n",i),ch = 1;
	if(!ch)	printf("no\n");
    return 0;
}
