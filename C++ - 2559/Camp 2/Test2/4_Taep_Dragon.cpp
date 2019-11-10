/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[25][25];
int main(){
    int r,c,k,p,q,i,j;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d %d",&r,&c,&k,&p);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                mic[i][j]=1;
        for(z=0;z<k;z++){
            for(i=0;i<r;i++)
                for(j=0;j<c;j++)
                    temp[i][j]=mic[i][j]+mic[i-1][j]+mic[i+1][j]+mic[i][j-1]+mic[i][j+1];
        }
    }
return 0;
}
