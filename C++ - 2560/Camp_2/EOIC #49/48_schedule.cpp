/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int day[1010][1010],hr[1010][1010],a[1010],b[1010];
int main()
{
    int m,i,j,n,d1,d2,h1,h2;
    scanf("%d %d",&m,&n);
    day[0][0]=1;
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        day[i][0]=day[i-1][0];
        if(hr[i-1][0]+a[i]>m)
            day[i][0]++,hr[i][0]=a[i];
        else
            hr[i][0]=hr[i-1][0]+a[i];
    }
    for(i=1;i<=n;i++){
        scanf("%d",&b[i]);
        day[0][i]=day[0][i-1];
        if(hr[0][i-1]+b[i]>m)
            day[0][i]++,hr[0][i]=b[i];
        else
            hr[0][i]=hr[0][i-1]+b[i];
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            d1=day[i][j-1];
            if(hr[i][j-1]+b[j]>m)
                d1++,h1=b[j];
            else
                h1=hr[i][j-1]+b[j];
            d2=day[i-1][j];
            if(hr[i-1][j]+a[i]>m)
                d2++,h2=a[i];
            else
                h2=hr[i-1][j]+a[i];
            if(d1<d2 || (d1==d2 && h1<h2))
                day[i][j]=d1,hr[i][j]=h1;
            else
                day[i][j]=d2,hr[i][j]=h2;
        }
    }
    printf("%d\n%d\n",day[n][n],hr[n][n]);
    return 0;
}
