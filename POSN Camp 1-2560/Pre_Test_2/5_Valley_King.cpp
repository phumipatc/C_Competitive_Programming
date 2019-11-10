#include<bits/stdc++.h>
using namespace std;
int a[1200];
int main(){
    int q,n,point,i,ch;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        point=0,ch=0;
        for(i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        for(i=0;i<n;i++){
            if(a[i]==a[i+1]){
                a[i]=a[i+1]=0;
                point++;
                i++;
            }
        }
        printf("%d\n",point);
        for(i=0;i<n;i++){
            if(a[i]!=0){
                ch=1;
                printf("%d ",a[i]);
            }
        }
        if(ch){
            printf("\n");
        }else{
            printf("Empty\n");
        }
    }
    return 0;
}
