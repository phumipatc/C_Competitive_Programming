/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int fw[2010][2010],n;
void update(int x,int y,int c){
    for(int i=x;i<=n;i+=(i&(-i))){
        for(int j=y;j<=n;j+=(j&(-j))){
            fw[i][j]+=c;
        }
    }
}
int query(int x,int y){
    int sum = 0;
    for(int i=x;i>=1;i-=(i&(-i))){
        for(int j=y;j>=1;j-=(j&(-j))){
            sum+=fw[i][j];
        }
    }
    return sum;
}
int main(){
    int opr,x1,y1,x2,y2,c;
    scanf("%d %d",&opr,&n);
    while(opr!=3){
        scanf("%d",&opr);
        if(opr == 1){
            scanf("%d %d %d",&x1,&y1,&c);
            x1++,y1++;
            update(x1,y1,c);
        }else if(opr == 2){
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            x1++,y1++,x2++,y2++;
            printf("%d\n",query(x2,y2)-query(x1-1,y2)-query(x2,y1-1)+query(x1-1,y1-1));
        }
    }
    return 0;
}
