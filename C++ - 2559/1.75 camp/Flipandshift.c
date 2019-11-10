#include<stdio.h>
#include<math.h>
int main(){
    int q,n,i,kuu,kee,num;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        kuu=0,kee=0;
        for(i=0;i<n;i++){
            scanf("%d",&num);
            if(num){
                if(i%2==0)
                    kuu++;
                else
                    kee++;
            }
        }
        if(n%2==1 || abs(kuu-kee)<=1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
