/*
TASK: Border
LANG: C++
AUTHOR: PeaTT~
*/
#include <cstdio>
#include <algorithm>
using namespace std;
int a[300][300],b[15000];
int main(){
	int n,k,i,j,coun=0,sum=0;
	scanf("%d %d",&n,&k);
	for(i=0;i<2*n+1;i++){
        for(j=0;j<n+1;j++){
            if(i%2==0 && j==n)  continue;
            scanf("%d",&a[i][j]);
        }
	}
	for(i=0;i<2*n;i+=2){
        for(j=0;j<n;j++){
            b[coun++]= 3*(a[i][j]-a[i+2][j])+5*(a[i+1][j]-a[i+1][j+1]);
        }
	}
	sort(b,b+coun);
	for(i=0;i<k;i++)
        sum+=b[i];
    printf("%d\n",sum);
	return 0;
}
