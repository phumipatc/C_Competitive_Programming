/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[2010][2010],ans[4010],temp[4010];
int r,c;
void dfs(int i,int j){
    temp[i+j-1] = a[i][j];
    if(ans[1]!=0 && strncmp(ans+1,temp+1,i+j-1)<0)  return ;
    if(i == r && j == c){
        if(ans[1] == 0){
            strcpy(ans+1,temp+1);
        }else{
            if(strcmp(ans+1,temp+1)>0)
                strcpy(ans+1,temp+1);
        }
        return ;
    }
    if(i+1<=r && j+1<=c){
        if(a[i+1][j]<a[i][j+1])         dfs(i+1,j);
        else if(a[i+1][j]>a[i][j+1])    dfs(i,j+1);
        else                            dfs(i+1,j),dfs(i,j+1);
    }else if(i+1<=r)                    dfs(i+1,j);
    else                                dfs(i,j+1);
}
int main(){
    scanf("%d %d",&r,&c);
    for(long long i=1;i<=r;i++)
        for(long long j=1;j<=c;j++)
            scanf(" %c",&a[i][j]);
    dfs(1,1);
    printf("%s\n",ans+1);
	return 0;
}