/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
double val[255],st[255][255],ans[255][255],temp[255][255];
void multi(int n,int a){
    if(n==1){
        for(int i=0; i<a; i++)
            for(int j=0; j<a; j++)
                ans[i][j]=st[i][j];
        return;
    }
    multi(n/2,a);
    for(int i=0; i<a; i++){
        for(int j=0; j<a; j++){
            temp[i][j]=0;
            for(int k=0; k<a; k++)
                temp[i][j]+=ans[i][k]*ans[k][j];
        }
    }
    for(int i=0; i<a; i++)
        for(int j=0; j<a; j++)
            ans[i][j]=temp[i][j];
    if(n%2==1){
        for(int i=0; i<a; i++){
            for(int j=0; j<a; j++){
                temp[i][j]=0;
                for(int k=0; k<a; k++)
                    temp[i][j]+=ans[i][k]*st[k][j];
            }
        }
    }
    for(int i=0; i<a; i++)
        for(int j=0; j<a; j++)
            ans[i][j]=temp[i][j];
    return;
}
int main()
{
    int n,t,i,j;
    scanf("%d %d",&n,&t);
    for(i=0;i<n;i++)
        scanf("%lf",&val[i]);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%lf",&st[i][j]);
    multi(t,n);
    for(i=0;i<n;i++){
        double sum=0;
        for(j=0;j<n;j++)
            sum+=val[j]*ans[j][i];
        printf("%.2lf\n",sum);
    }
    return 0;
}
/**/

