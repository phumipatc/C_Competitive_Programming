/*
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[12][100];
int main(){
    ios_base::sync_with_stdio(0);	cin.tie(0); cout.tie(0);
    int n,ni,nj,st,h,maxi = 0,maxj = 0;
    memset(a,'.',sizeof a);
    cin >> n;
    while(n--){
        scanf("%d %d",&st,&h);
        nj = st,ni = 1;
        for(int i=1;i<=h;i++){
            if(a[ni][nj] == '/' || a[ni][nj] == 'v')    a[ni][nj] = 'v';
            else                                        a[ni][nj] = '\\';
            maxi = max(maxi,ni);
            ni++,nj++;
        }
        ni--;
        for(int i=1;i<=h;i++){
            if(a[ni][nj] == '\\' || a[ni][nj] == 'v')   a[ni][nj] = 'v';
            else                                        a[ni][nj] = '/';
            maxj = max(maxj,nj);
            ni--,nj++;
        }
    }
    for(int j=1;j<=maxj;j++){
        int ch = 0;
        for(int i=maxi;i>0;i--){
            if(ch)                      a[i][j] = 'X';
            else if(a[i][j] == '/')     a[i][j] = '\\',ch = 1;
            else if(a[i][j] == '\\')    a[i][j] = '/',ch = 1;
            else if(a[i][j] == 'v')     ch = 1;
        }
    }
    for(int i=maxi;i>0;i--){
        for(int j=1;j<=maxj;j++){
            printf("%c",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}