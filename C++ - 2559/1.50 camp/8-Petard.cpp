/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<cstdio>
using namespace std;
int mic[6000][6000];
int main(){
    int r,c,k,i,j,num,maxx=0;
    scanf("%d %d %d",&r,&c,&k);
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            scanf("%d",&num);
            mic[i][j]=mic[i-1][j]+mic[i][j-1]-mic[i-1][j-1]+num;
        }
    }
    for(i=1;i<=r-k+1;i++){
        for(j=1;j<=c-k+1;j++){
            if(mic[i+k-1][j+k-1]-mic[i+k-1][j-1]-mic[i-1][j+k-1]+mic[i-1][j-1]>maxx)
                maxx=mic[i+k-1][j+k-1]-mic[i+k-1][j-1]-mic[i-1][j+k-1]+mic[i-1][j-1];
        }
    }
    printf("%d",maxx);
return 0;
}
