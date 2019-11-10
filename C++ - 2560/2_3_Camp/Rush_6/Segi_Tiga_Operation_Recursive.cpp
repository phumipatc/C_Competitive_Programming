/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[260];
int mic[260][260][3],mark[260][260],n;
void divide(int l,int r){
    if(mic[1][n][0])    return ;
    if(l==r)            return ;
    if(mark[l][r])      return ;
    mark[l][r]=1;
    for(int k=l;k<r;k++){
        divide(l,k);
        divide(k+1,r);
        for(int ch1=0;ch1<3;ch1++){
            for(int ch2=0;ch2<3;ch2++){
                if(mic[l][k][ch1]!=1 || mic[k+1][r][ch2]!=1)    continue;
                if(ch1==0){
                    if(ch2==0)  mic[l][r][2]=1;
                    if(ch2==1)  mic[l][r][1]=1;
                    if(ch2==2)  mic[l][r][0]=1;
                }
                if(ch1==1){
                    if(ch2==0)  mic[l][r][2]=1;
                    if(ch2==1)  mic[l][r][1]=1;
                    if(ch2==2)  mic[l][r][1]=1;
                }
                if(ch1==2){
                    if(ch2==0)  mic[l][r][1]=1;
                    if(ch2==1)  mic[l][r][2]=1;
                    if(ch2==2)  mic[l][r][1]=1;
                }
                if(mic[1][n][0])
                    return ;
            }
        }
    }
}
int main(){
    int q=20;
    while(q--){
        scanf("%d %s",&n,str+1);
        for(int i=1;i<=n;i++)
            mark[i][i] = 1,mic[i][i][str[i]-'0']=1;
        divide(1,n);
        if(mic[1][n][0])    printf("yes\n");
        else                printf("no\n");
        memset(mic,0,sizeof mic);
        memset(mark,0,sizeof mark);
    }
    return 0;
}
