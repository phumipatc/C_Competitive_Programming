/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010],b[5];
int main()
{
    int n,i,j,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        b[a[i]]++;
    }
    for(i=0;i<b[1];i++){
        if(a[i]==2){
            for(j=b[1];j<n;j++){
                if(a[j]==1){
                    a[i]=1;
                    a[j]=2;
                    ans++;
                    break;
                }
            }
        }else if(a[i]==3){
            for(j=b[1]+b[2];j<n;j++){
                if(a[j]==1){
                    a[i]=1;
                    a[j]=3;
                    ans++;
                    break;
                }
            }
            if(j==n){
                for(j=b[1];j<b[1]+b[2];j++){
                    if(a[j]==1){
                        a[i]=1;
                        a[j]=3;
                        ans++;
                        break;
                    }
                }
            }
        }
    }
    for(i=b[1];i<b[1]+b[2];i++){
        if(a[i]==3){
            for(j=b[1]+b[2];j<n;j++){
                if(a[j]==2){
                    a[i]=2;
                    a[j]=3;
                    ans++;
                    break;
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
/*
8
2 2 1 3 3 2 3 1
*/
