/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<stdio.h>
int a[1200];
int main(){
    int t,n,countt,maxx,ans,i;
    scanf("%d",&t);
    while(t--){
        maxx=-1;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        countt=0;
        for(i=0;i<n;i++){
            if(a[i]==1){
                if(countt%2==1){
                    if(countt>maxx){
                        maxx=countt;
                        ans=i-maxx/2-1;
                    }
                }
                countt=0;
            }else if(a[i]==0)
                countt++;
        }
        if(countt%2==1){
            if(countt>maxx){
                maxx=countt;
                ans=i-maxx/2-1;
            }
        }
    }
    return 0;
}
