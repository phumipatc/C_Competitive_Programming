/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[110][110];
int qs[110][110];
int main(){
    int r,c,k,eni,enj;
    scanf("%d %d %d",&r,&c,&k);
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j] == '*')  qs[i][j]++;
            qs[i][j]+=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        }
    }
    int countt,maxx = 0;
    for(int i=k;i<=r;i++){
        for(int j=k;j<=c;j++){
            countt = qs[i-1][j-1]-qs[i-1][j-k+1]-qs[i-k+1][j-1]+qs[i-k+1][j-k+1];
            if(countt>maxx){
                maxx = countt;
                eni = i,enj = j;
            }
        }
    }
    for(int i=eni-k+1;i<=eni;i++)
        a[i][enj-k+1] = a[i][enj] = '|';
    for(int j=enj-k+1;j<=enj;j++)
        a[eni-k+1][j] = a[eni][j] = '-';
    a[eni-k+1][enj-k+1] = a[eni-k+1][enj] = a[eni][enj-k+1] = a[eni][enj] = '+';
    printf("%d\n",maxx);
    for(int i=1;i<=r;i++)
        printf("%s\n",a[i]+1);
	return 0;
}