#include<stdio.h>
int main(){
    int a,maxx=0,countt=0,q,n,i,b[1001],c;
    scanf("%d",&q);
    while(q--){
        maxx=-1;
        countt=0;
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&b[i]);
            if(b[i]==0){
                countt++;
            }else if(b[i]==1){
                if(countt%2 && maxx<countt){
                    maxx=countt;
                    c=i-((countt+1)/2);
                }
                countt=0;
            }

        }
        if(countt%2 && maxx<countt){
            maxx=countt;
            c=i-((countt+1)/2);
        }
        countt=0;
        if(maxx!=-1)    printf("%d\n",c);
        else            printf("-1\n");
    }
}
