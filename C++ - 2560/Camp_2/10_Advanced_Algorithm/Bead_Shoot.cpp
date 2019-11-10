/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main()
{
    int n,i,j,x,temp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        if(i>0 && a[i-1]==0){
            a[i]=x;
            j=i;
            while(j>0 && a[j]>=a[j-1])
                a[j-1]=a[j]+1,j--;
        }else{
            a[i]=x;
            j=i;
            while(j>0 && a[j]>=a[j-1]){
                temp=a[j];
                a[j]=a[j-1]-1;
                if(temp-1>a[j-1])
                    a[j-1]=temp-1;
                j--;
            }
        }
    }
    for(j=0;j<n;j++)
        printf("%d\n",a[j]);
    return 0;
}
