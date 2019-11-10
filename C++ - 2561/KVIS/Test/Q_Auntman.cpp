/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
int dirx[2][8] = {{-2,-1,-1,-2,2,1,1,2},{-2,-1,1,2,-2,-1,1,2}};
int diry[2][4] = {{-1,1,0,0},{0,0,1,-1}};
int main(){
    int r,c;
    cin >> r >> c;
    for(int i=1;i<=r;i++)
        cin >> a[i]+1;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(a[i][j] == 'x'){
                for(int k=0;k<8;k++){
                    if(i+dirx[0][k]<1 || j+dirx[1][k]<1)    continue;
                    if(a[i+dirx[0][k]][j+dirx[1][k]] == 'A')
                        a[i+dirx[0][k]][j+dirx[1][k]] = '.';
                }
                a[i][j] = '.';
            }
            if(a[i][j] == '+'){
                for(int k=0;k<4;k++){
                    if(i+diry[0][k]<1 || j+diry[1][k]<1)    continue;
                    if(a[i+diry[0][k]][j+diry[1][k]] == 'A')
                        a[i+diry[0][k]][j+diry[1][k]] = '.';
                }
                a[i][j] = '.';
            }
        }
    }
    int countt = 0;
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            if(a[i][j] == 'A')
                countt++;
    printf("%d\n",countt);
    for(int i=1;i<=r;i++)
        printf("%s\n",a[i]+1);
	return 0;
}
