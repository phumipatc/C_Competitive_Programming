/*
	Task :
	Author : Phumipat C.
	Lang : C
	School : RYW
*/
#include<stdio.h>
int main(){
    int n,a,b,c,opr;
    scanf("%d",&n);
    while(n--){
        scanf("%d/%d/%d %d",&a,&b,&c,&opr);
        if(opr == 2){
            if(a<10)    printf("0");
            printf("%d ",a);
            switch(b){
                case 1:printf("January");     break;
                case 2:printf("February");    break;
                case 3:printf("March");       break;
                case 4:printf("April");       break;
                case 5:printf("May");         break;
                case 6:printf("June");        break;
                case 7:printf("July");        break;
                case 8:printf("August");      break;
                case 9:printf("September");   break;
                case 10:printf("October");    break;
                case 11:printf("November");   break;
                case 12:printf("December");   break;
            }
            printf(", %d\n",c);
        }else if(opr == 3){
            switch(b){
                case 1:printf("January");     break;
                case 2:printf("February");    break;
                case 3:printf("March");       break;
                case 4:printf("April");       break;
                case 5:printf("May");         break;
                case 6:printf("June");        break;
                case 7:printf("July");        break;
                case 8:printf("August");      break;
                case 9:printf("September");   break;
                case 10:printf("October");    break;
                case 11:printf("November");   break;
                case 12:printf("December");   break;
            }
            if(a<10)    printf(" 0%d, %d\n",a,c);
            else        printf(" %d, %d\n",a,c);
        }else if(opr == 4){
            if(a<10)    printf("0%d ",a);
            else        printf("%d ",a);
            switch(b){
                case 1:printf("January");     break;
                case 2:printf("February");    break;
                case 3:printf("March");       break;
                case 4:printf("April");       break;
                case 5:printf("May");         break;
                case 6:printf("June");        break;
                case 7:printf("July");        break;
                case 8:printf("August");      break;
                case 9:printf("September");   break;
                case 10:printf("October");    break;
                case 11:printf("November");   break;
                case 12:printf("December");   break;
            }
            printf(", %d\n",c%100);
        }
    }
	return 0;
}
