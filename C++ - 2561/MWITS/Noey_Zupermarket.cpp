/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int a[1010];
int main(){
    int n,ans = 0,temp,i,j,ch = 1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        a[i] = temp-a[i];
    }
    while(ch){
        ch = 0;
        for(i=1;i<=n;){
            if(!a[i]){
                i++;
                continue;
            }
            ch = 1;
            if(a[i]>0){
                temp = 1e9;
                for(j=i;j<=n && a[j]>0;j++)
                    temp = min(temp,a[j]);
                // printf("%d %d\n",i,j);
                while(i<j)
                    a[i]-=temp,i++;
            }else if(a[i]<0){
                temp = -1e9;
                for(j=i;j<=n && a[j]<0;j++)
                    temp = max(temp,a[j]);
                // printf("%d %d\n",i,j);
                while(i<j)
                    a[i]-=temp,i++;
            }
            // for(int j=1;j<=n;j++)
                // printf("%d ",a[j]);
            ans+=abs(temp);
            // printf("\n%d\n",ans);
        }
    }
    printf("%d\n",ans);
	return 0;
}
