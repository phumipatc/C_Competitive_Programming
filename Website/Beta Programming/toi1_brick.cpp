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
char a[100][100];
int main(){
    int r,c,i,j,k;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf(" %c",&a[i][j]);
    for(i=0;i<c;i++){
        scanf("%d",&k);
        for(j=0;j<r;j++){
            if(a[j][i]=='O')
                break;
        }
        j--;
        while(k>0 && j>=0)
            a[j][i]='#',j--,k--;
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
