/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[3010][3010];
int ship[3010],ground[3010];
int main(){
    int r,c,minn=1e9;
    scanf("%d %d",&r,&c);
    for(int i=1;i<=c;i++)
        ground[i] = 1e9;
    for(int i=1;i<=r;i++){
        scanf(" %s",str[i]+1);
        for(int j=1;j<=c;j++){
            if(str[i][j] == 'X')
                ship[j] = max(ship[j],i);
            else if(str[i][j] == '#' && ship[j]!=0){
                ground[j] = min(ground[j],i);
            }
        }
    }
    for(int i=1;i<=c;i++)
        minn = min(minn,ground[i]-ship[i]-1);
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(i-minn>0 && str[i-minn][j] == 'X')   printf("X");
            else if(str[i][j] == '#')               printf("#");
            else                                    printf(".");
        }
        printf("\n");
    }
    return 0;
}
