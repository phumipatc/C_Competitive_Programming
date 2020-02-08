/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int n;
struct A{
    double a[255][255];
    A operator * (const A&o) const{
        A temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp.a[i][j] = 0;
                for(int k=0;k<n;k++){
                    temp.a[i][j]+=a[i][k]*o.a[k][j];
                }
            }
        }
        return temp;
    }
};
A p[22],ans;
int c[255];
int main(){
    int t;
    double sum;
    scanf("%d %d",&n,&t);
    for(int i=0;i<n;i++)
        scanf("%d",&c[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%lf",&p[0].a[j][i]);
    for(int i=1;i<20;i++)
        p[i] = p[i-1]*p[i-1];
    for(int i=0;i<n;i++)
        ans.a[i][i] = 1;
    for(int i=0;i<20;i++)
        if(t & (1<<i))
            ans = ans*p[i];
    for(int i=0;i<n;i++){
        sum = 0;
        for(int j=0;j<n;j++)
            sum+=c[j]*ans.a[i][j];
        printf("%.2lf\n",sum);
    }
	return 0;
}
