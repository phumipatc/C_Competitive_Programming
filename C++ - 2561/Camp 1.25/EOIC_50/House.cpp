/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010][1010],p[1010][1010],m[1010][1010];
int main(){
    int r,c,k,temp;
    scanf("%d %d %d",&r,&c,&k);
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            temp = pr[i];
            pr[i] = mr[i]+a[i][j];
            mr[i] = temp-a[i][j];
            temp = pc[j];
            pc[j] = mc[j]+a[i][j];
            mc[j] = temp-a[i][j];
        }
    }
	return 0;
}
