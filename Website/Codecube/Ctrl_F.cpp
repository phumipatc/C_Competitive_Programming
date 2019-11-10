/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1200],b[1200];
int main(){
    int i,j,n,m,countt=0;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        scanf(" %c",&a[i]);
    for(i=0;i<m;i++)
        scanf(" %c",&b[i]);
    for(i=0;i<n;i++){
        int t=0;
        if(a[i]==b[t]){
            t++;
            for(j=i+1;j<i+m;j++){
                if(a[j]!=b[t]){
                    break;
                }else if(j==i+m-1 && a[j]==b[t]){
                    countt++;
                }
                t++;
            }
        }
    }
    printf("%d\n",countt);
return 0;
}
