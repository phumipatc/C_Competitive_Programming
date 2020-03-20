/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char a[20][20];
vector<char > v;
int main(){
	int r,c,degree;
	scanf("%d %d",&r,&c);
	for(int i=1;i<=r;i++)
		scanf(" %s",a[i]+1);
	scanf("%d",&degree);
	if(degree == 0 || degree == 360){
		for(int i=1;i<=r;i++){
			for(int j=1;j<=c;j++)
				v.push_back(a[i][j]);
			v.push_back('0');
		}
	}else if(degree == 90){
		for(int j=1;j<=c;j++){
			for(int i=r;i>=1;i--)
				v.push_back(a[i][j]);
			v.push_back('0');
		}
	}else if(degree == 180){
		for(int i=r;i>=1;i--){
			for(int j=c;j>=1;j--)
				v.push_back(a[i][j]);
			v.push_back('0');
		}
	}else if(degree == 270){
		for(int j=c;j>=1;j--){
			for(int i=1;i<=r;i++)
				v.push_back(a[i][j]);
			v.push_back('0');
		}
	}else{
		int i,j,ii,jj;
		if(degree == 45){
			i = 1,j = 1;
			while(i<=r && j<=c){
				ii = i,jj = j;
				while(ii>=1 && jj<=c){
					v.push_back(a[ii][jj]);
					ii--,jj++;
				}
				v.push_back('0');
				if(i<r)	i++;
				else	j++;
			}
		}else if(degree == 135){
			i = r,j = 1;
			while(i>=1 && j<=c){
				ii = i,jj = j;
				while(ii>=1 && jj>=1){
					v.push_back(a[ii][jj]);
					ii--,jj--;
				}
				v.push_back('0');
				if(j<c)	j++;
				else	i--;
			}
		}else if(degree == 225){
			i = r,j = c;
			while(i>=1 && j>=1){
				ii = i,jj = j;
				while(ii<=r && jj>=1){
					v.push_back(a[ii][jj]);
					ii++,jj--;
				}
				v.push_back('0');
				if(i>1)	i--;
				else	j--;
			}
		}else if(degree == 315){
			i = 1,j = c;
			while(i<=r && j<=c){
				ii = i,jj = j;
				while(ii<=r && jj<=c){
					v.push_back(a[ii][jj]);
					ii++,jj++;
				}
				v.push_back('0');
				if(j>1)	j--;
				else	i++;
			}
		}
	}
	if(degree%90 == 0){
		for(auto x:v){
			if(x == '0')	printf("\n");
			else			printf("%c",x);
		}
	}else{
		if(degree == 45 || degree == 225){
			int x = 0;
			for(int i=1;i<=r;i++){
				for(int j=i;j<r;j++)
					printf("-");
				printf("%c",v[x]);
				x++;
				while(x<v.size() && v[x]!='0'){
					printf("-%c",v[x]);
					x++;
				}
				x++;
				printf("\n");
			}
			for(int i=1;i<c;i++){
				for(int j=1;j<=i;j++)
					printf("-");
				printf("%c",v[x]);
				x++;
				while(x<v.size() && v[x]!='0'){
					printf("-%c",v[x]);
					x++;
				}
				x++;
				printf("\n");
			}
		}else{
			int x = 0;
			for(int i=1;i<=c;i++){
				for(int j=i;j<c;j++)
					printf("-");
				printf("%c",v[x]);
				x++;
				while(x<v.size() && v[x]!='0'){
					printf("-%c",v[x]);
					x++;
				}
				x++;
				printf("\n");
			}
			for(int i=1;i<r;i++){
				for(int j=1;j<=i;j++)
					printf("-");
				printf("%c",v[x]);
				x++;
				while(x<v.size() && v[x]!='0'){
					printf("-%c",v[x]);
					x++;
				}
				x++;
				printf("\n");
			}
		}
	}
	return 0;
}