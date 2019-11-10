/*
    AUTHOR: Magnam Caritatem
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,temp;
	scanf("%d",&n);
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<=n-1;j++){
			if(i&(1<<j))	continue;
			temp = i|(1<<j);
			for(int k=n-1;k>=0;k--){
				if(i&(1<<k))	printf("1");
				else			printf("0");
			}
			printf(" ");
			for(int k=n-1;k>=0;k--){
				if(temp&(1<<k))	printf("1");
				else			printf("0");
			}
			printf("\n");
		}
	}
    return 0;
}
