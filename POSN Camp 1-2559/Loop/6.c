/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
int main()
{
    int i,n,d,m,y,a;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d/%d/%d %d",&d,&m,&y,&a);
        if(d<=31 && d>=1 && m>=1 && m<=12 && y>=1000 && y<=3000 && a<5 && a>1){
        if(a==2){
            printf("%02d ",d);
            switch(m){
                case 1 : printf("January,"); break;
                case 2 : printf("February,"); break;
                case 3 : printf("March,"); break;
                case 4 : printf("April,"); break;
                case 5 : printf("May,"); break;
                case 6 : printf("June,"); break;
                case 7 : printf("July,"); break;
                case 8 : printf("August,"); break;
                case 9 : printf("September,"); break;
                case 10: printf("October,"); break;
                case 11: printf("November,"); break;
                case 12: printf("December,"); break;
            }
            printf("%d",y);
        }else if(a==3){
            switch(m){
                case 1 : printf("January "); break;
                case 2 : printf("February "); break;
                case 3 : printf("March "); break;
                case 4 : printf("April "); break;
                case 5 : printf("May "); break;
                case 6 : printf("June "); break;
                case 7 : printf("July "); break;
                case 8 : printf("August "); break;
                case 9 : printf("September "); break;
                case 10: printf("October "); break;
                case 11: printf("November "); break;
                case 12: printf("December "); break;
            }
            printf("%02d,",d);
            printf("%d",y);
        }else if(a==4){
            printf("%02d ",d);
            switch(m){
                case 1 : printf("January,"); break;
                case 2 : printf("February,"); break;
                case 3 : printf("March,"); break;
                case 4 : printf("April,"); break;
                case 5 : printf("May,"); break;
                case 6 : printf("June,"); break;
                case 7 : printf("July,"); break;
                case 8 : printf("August,"); break;
                case 9 : printf("September,"); break;
                case 10: printf("October,"); break;
                case 11: printf("November,"); break;
                case 12: printf("December,"); break;
            }
            printf("%02d",y%100);
        }
    }else{
        printf("No");
    }
    }
return 0;
}
