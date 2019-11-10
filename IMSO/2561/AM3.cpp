/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
	int r,g,b;
};
A a[110][110];
int countt[260][260][260];
int main(){
	// freopen("0_in.txt","r",stdin);
	// freopen("0_out.txt","w",stdout);
	int h,w;
	scanf("%d %d",&h,&w);
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			scanf("%d %d %d",&a[i][j].r,&a[i][j].g,&a[i][j].b);
			countt[a[i][j].r][a[i][j].g][a[i][j].b]++;
		}
	}
	int ans = 0;
	for(int i=0;i<=255;i++){
		for(int j=0;j<=255;j++){
			for(int k=0;k<=255;k++){
				if(countt[i][j][k]>=500)	ans+=countt[i][j][k];
			}
		}
	}
	printf("%d\n",ans);
	if(ans>=5000)	printf("A\n");
	// else if(ans)
    return 0;
}
