/*
    TASK: Printing date(date)
    AUTHOR: Phatcharapon
    SCHOOL: RYW
    LANG: C
            */
#include<stdio.h>
int main()
{
int i,n,m,d,a,j,y,k;
    scanf("%d",&n);

    for(a=1;a<=n;a++){
        scanf("%d/%d/%d %d",&d,&m,&y,&k);
        if(d<1||m<1||d>31||m>12||y<1000||y>3000||k>4||k<2||n>100000)
            printf("No");
        else
        if(k==2){
            printf("%02d ",d);
            switch(m){
            case 1:printf("January");break;
            case 2:printf("February");break;
            case 3:printf("March");break;
            case 4:printf("April");break;
            case 5:printf("May");break;
            case 6:printf("June");break;
            case 7:printf("July");break;
            case 8:printf("August");break;
            case 9:printf("September");break;
            case 10:printf("October");break;
            case 11:printf("November");break;
            case 12:printf("December");break;
        }
            printf(",%d",y);
        }else if(k==3){
            switch(m){
            case 1:printf("January");break;
            case 2:printf("February");break;
            case 3:printf("March");break;
            case 4:printf("April");break;
            case 5:printf("May");break;
            case 6:printf("June");break;
            case 7:printf("July");break;
            case 8:printf("August");break;
            case 9:printf("September");break;
            case 10:printf("October");break;
            case 11:printf("November");break;
            case 12:printf("December");break;
            }
            printf(" %02d,%d",d,y);
        }else{
            j=y%100;
            printf("%02d ",d);
            switch(m){
            case 1:printf("January");break;
            case 2:printf("February");break;
            case 3:printf("March");break;
            case 4:printf("April");break;
            case 5:printf("May");break;
            case 6:printf("June");break;
            case 7:printf("July");break;
            case 8:printf("August");break;
            case 9:printf("September");break;
            case 10:printf("October");break;
            case 11:printf("November");break;
            case 12:printf("December");break;
            }
            printf(",%02d",j);
        }

    }





       return 0;
}
