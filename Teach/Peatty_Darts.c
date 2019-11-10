/*
	Task :
	Author : Phumipat C.
	Lang : C
	School : RYW
*/
#include<stdio.h>
#include<math.h>
int main(){
    int n,x,y,sum = 0;
    double dis;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d",&x,&y);
        dis = sqrt((x*x) + (y*y));
        if(dis<=2)          sum+=5;
        else if(dis<=4)     sum+=4;
        else if(dis<=6)     sum+=3;
        else if(dis<=8)     sum+=2;
        else if(dis<=10)    sum++;
    }
    printf("%d\n",sum);
	return 0;
}
