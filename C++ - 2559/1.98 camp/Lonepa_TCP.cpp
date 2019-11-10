/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int main(){
    int t,r,c,i,j,num,maxx,k;
    char d;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&r,&c);
        for(i=1;i<=r;i++){
            for(j=1;j<=c;j++){
                scanf(" %c",&d);
                if(d=='#')
                    num=1;
                else
                    num=0;
                a[i][j]=num+a[i][j-1]+a[i-1][j]-a[i-1][j-1];
            }
        }
        maxx=0;
        for(i=1;i<=r;i++){
            for(j=1;j<=c;j++){
                for(k=1;i+k<=r && j+k<=c;k++){
                    if(a[i+k][j+k]-a[i+k][j-1]-a[i-1][j+k]+a[i-1][j-1]==1){
                        if(k>maxx)
                            maxx=k;
                    }
                }
            }
        }
        printf("%d",maxx+1);
    }
return 0;
}
