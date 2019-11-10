/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
pair<int ,int > ans[410];
int mark[25][25];
int r,c,ch;
void jump(int i,int j,int state){
    if(ch)  return ;
    // printf("%d %d %d\n",i,j,state);
    ans[state] = {i,j};
    if(state == r*c){
        ch = 1;
        return ;
    }
    for(int k=1;k<=r;k++){
        for(int l=1;l<=c;l++){
            if(i == k || l == j || i+j == k+l || i-j == k-l)    continue;
            if(mark[k][l])                                      continue;
            mark[k][l] = 1;
            jump(k,l,state+1);
            mark[k][l] = 0;
        }
    }
}
int main(){
    int q;
    scanf("%d",&q);
    for(int k=1;k<=q;k++){
        scanf("%d %d",&r,&c);
        ch = 0;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                memset(mark,0,sizeof mark);
                mark[i][j] = 1;
                jump(i,j,1);
                mark[i][j] = 0;
                if(ch)  goto next;
            }
        }
        next:;
        if(!ch) printf("Case #%d: IMPOSSIBLE\n",k);
        else{
            printf("Case #%d: POSSIBLE\n",k);
            for(int i=1;i<=r*c;i++)
                printf("%d %d\n",ans[i].first,ans[i].second);
        }
    }
	return 0;
}
