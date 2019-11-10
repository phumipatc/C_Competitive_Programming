#include<stdio.h>
int main(){
    int x;
    scanf("%d",&x);
    if(x>0){
    printf("Positive Integer");
}else if(x<0){
    printf("Negative Integer");
}else{
    printf("Zero Integer");
}
    return 0;
}

