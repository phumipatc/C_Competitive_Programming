#include<stdio.h>
int g[1500];
int main()
{
    int q,t,i,Max=0;
    int s,cou=0,num=0;
    scanf("%d",&t);
    for(q=0;q<t;q++){
        scanf("%d",&s);
        for(i=0;i<s;i++){
            scanf("%d",&g[i]);
            if(g[i]==0){
                cou++;
            }else if(g[i]==1){
                if(cou%2==1){
                    if(cou>Max){
                        Max=cou;
                        num=i-1;
                    }
                }cou=0;
            }
        }
        if(cou%2==1){
            if(cou>Max){
                Max=cou;
                num=i-1;
            }
        }
        if(Max==0){
            printf("-1\n");
        }else{
            num=num-(Max/2);
            printf("%d\n",num);
        }
        Max=0;num=0;s=0;cou=0;
    }
}
