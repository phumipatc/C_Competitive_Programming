/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[100][100];
int main(){
    int r,c,i,j,k;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf(" %c",&a[i][j]);
    for(i=0;i<c;i++){
        scanf("%d",&k);
        for(j=0;j<r;j++){
            if(a[j][i]=='O')
                break;
        }
        j--;
        while(k>0 && j>=0)
            a[j][i]='#',j--,k--;
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
