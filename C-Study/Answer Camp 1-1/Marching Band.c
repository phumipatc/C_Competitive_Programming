#include<stdio.h>
int main(){
    int q,a,b;
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&a,&b);
        printf("%d %d\n",(2*a)+(2*b),a*b);
    }
}
