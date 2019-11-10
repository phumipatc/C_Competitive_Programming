/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mark[360][640];
int main(){
    int w,h,x,y,wid,hei,num;
    char opr;
    scanf(" %c %d %d",&opr,&w,&h);
    while(1){
        scanf(" %c",&opr);
        if(opr == 'T')  break;
        if(opr == 'C'){
            scanf("%d %d %d %d %d",&num,&x,&y,&wid,&hei);
            for(int i=y;i<=min(h,y+hei-1);i++)
                for(int j=x;j<=min(w,x+wid-1);j++)
                    mark[i][j] = num;
        }else{
            scanf("%d %d",&x,&y);
            printf("%d\n",mark[y][x]);
        }
    }
	return 0;
}