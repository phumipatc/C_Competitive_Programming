/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[5][5],mark[5][5];
void change(int i,int j){
    a[i][j] = !a[i][j];
    a[i-1][j] = !a[i-1][j];
    a[i+1][j] = !a[i+1][j];
    a[i][j-1] = !a[i][j-1];
    a[i][j+1] = !a[i][j+1];
}
int ans = 1e9;
void check(int i,int j,int state){
    int ch = 1;
    for(int ii=1;ii<=4;ii++){
        for(int jj=1;jj<=4;jj++){
            if(a[ii][jj]!=a[1][1]){
                ch = 0;
                break;
            }
        }
    }
    if(ch){
        ans = min(ans,state);
        return ;
    }
    if(i<1 || j<1 || i>4 || j>4)    return ;
//    printf("%d %d %d\n",i,j,state);
    if(j == 4)  check(i+1,1,state);
    else        check(i,j+1,state);
    change(i,j);
    if(j == 4)  check(i+1,1,state+1);
    else        check(i,j+1,state+1);
    change(i,j);
}
int main(){
    char str;
    for(int i=1;i<=4;i++){
        for(int j=1;j<=4;j++){
            scanf(" %c",&str);
            if(str == 'b')  a[i][j] = 0;
            else            a[i][j] = 1;
        }
    }
    check(1,1,0);
    if(ans == 1e9)  printf("Impossible\n");
    else            printf("%d\n",ans);
	return 0;
}
