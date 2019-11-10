/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int r[1010][1010],s[1010][1010];
int main(){
	int w,h,n,a,b,c,d,i,j;
	scanf("%d %d %d",&w,&h,&n);
	while(n--){
		scanf("%d %d %d %d",&b,&a,&d,&c);
		r[a][b]++;
		r[a][d+1]--;
		r[c+1][b]--;
		r[c+1][d+1]++;
	}
	for(i=1;i<=h;i++){
		for(j=1;j<=w;j++){
            r[i][j]+=r[i][j-1];
            s[i][j]=s[i-1][j]+r[i][j];
		}
	}
	for(i=1;i<=h;i++){
		for(j=1;j<=w;j++){
            printf("%d",s[i][j]%2);
		}
		printf("\n");
	}
	return 0;
}
