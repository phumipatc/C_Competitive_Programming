#include<stdio.h>
int main(){
    int a[10],i,k,c=0;
    for(i=0;i<4;i++){
        scanf("%d",&a[i]);
    }
    while(a[0]!=0 || a[1]!=0 || a[2]!=0 || a[3]!=0){
        k=a[0];
        a[0]=abs(a[0]-a[1]);
        a[1]=abs(a[1]-a[2]);
        a[2]=abs(a[2]-a[3]);
        a[3]=abs(a[3]-k);
        printf("%d %d %d %d\n",a[0],a[1],a[2],a[3]);
        c++;
    }
    printf("%d",c);
    return 0;
}
