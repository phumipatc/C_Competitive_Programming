/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	int x,y;
};
A a[1010];
map<double ,map<double ,int > > mapp;
int main(){
	int n,all = 0,ans = 0;
	double m,b;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&a[i].x,&a[i].y);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
            if(a[i].x == a[j].x)        m = 1e6;
            else if(a[i].y-a[j].y == 0) m = 0;
            else                        m = ((double )a[i].y-a[j].y)/((double )a[i].x-a[j].x);
			b = (m*(-a[i].x))+a[i].y;
			if(!mapp[m][b]){
                ans+=all-(mapp[m].size()-1);
				mapp[m][b]++;
				all++;
			}
			printf("%d %d %lf %lf %d %d %d\n",i,j,m,b,all,mapp[m].size(),ans);
		}
	}
	printf("%d\n",ans);
	return 0;
}
