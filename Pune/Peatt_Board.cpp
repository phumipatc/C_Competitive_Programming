#include<bits/stdc++.h>
using namespace std;
int qs[1010][1010];
int main(){
	// freopen("0_in.txt","r",stdin);
	// freopen("0_out.txt","w",stdout);
	int w,h,n,i,j,k,l;
	scanf("%d %d %d",&w,&h,&n);
	while(n--){
		scanf("%d %d %d %d",&j,&i,&l,&k);
		qs[i][j]++;
		qs[i][l+1]--;
		qs[k+1][j]--;
		qs[k+1][l+1]++;
	}
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			qs[i][j]+=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
			printf("%d",qs[i][j]%2);
		}
		printf("\n");
	}
	return 0;
}