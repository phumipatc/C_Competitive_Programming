#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("0_in.txt","r",stdin);
	freopen("0_out.txt","w",stdout);
	int n,a,b,temp,c1 = 0,c2 = 0,c3,c4;
	scanf("%d",&n);
	for(int i=sqrt(n);i>=1;i--){
		if(n%i == 0){
			c3 = c4 = 0;
			temp = i;
			while(temp>=1){
				temp/=10;
				c3++;
			}
			temp = n/i;
			while(temp>=1){
				temp/=10;
				c4++;
			}
			// printf("%d : %d %d %d %d\n",i,c1,c2,c3,c4);
			if(c1+c2<c3+c4 && c1!=0)	break;
			if(c1 == 0 || c1+c2 == c3+c4){
				a = i;
				b = n/i;
				c1 = c3;
				c2 = c4;
			}
			// printf("%d %d\n",a,b);
		}
	}
	printf("%d%d\n",a,b);
    return 0;
}