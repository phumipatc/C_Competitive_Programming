#include<stdio.h>
#include<math.h>
int main(){
    float r;
    scanf("%f",&r);
    printf("%.2f\n%.2f",acos(-1)*r*r,4*acos(-1)*r*r*r/3);
    return 0;
}

