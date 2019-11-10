#include<stdio.h>

int main(){
    int a,b,c,n,i,j;
    scanf("%d %d %d",&a,&b,&c);
    for(i=-100;i<=100;i++){
        for(j=-100;j<=100;j++){
            if((a*i)+(b*i)==c) printf("Yes");
            else printf("No"); return 0;
        }
    }



    return 0;
}
