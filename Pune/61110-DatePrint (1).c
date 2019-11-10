#include<stdio.h>
int main(){
    int n,i,d,p,y,m;
    char pm;
    scanf("%d",&n);
    while(n--){
        scanf("%d / %d / %d %d",&d,&m,&y,&p);
        if(d<1 || d>31 || m<1 || m>12 || y<1000 || y>3000 || p<1 || p>4) printf("No");

        else if(p==2){
            if(m==1) printf("%02d January, %d",d,y);
            else if(m==2) printf("%02d February, %d",d,y);
            else if(m==3) printf("%02d March, %d",d,y);
            else if(m==4) printf("%02d April, %d",d,y);
            else if(m==5) printf("%02d May, %d",d,y);
            else if(m==6) printf("%02d June, %d",d,y);
            else if(m==7) printf("%02d July, %d",d,y);
            else if(m==8) printf("%02d August, %d",d,y);
            else if(m==9) printf("%02d September, %d",d,y);
            else if(m==10) printf("%02d October, %d",d,y);
            else if(m==11) printf("%02d November, %d",d,y);
            else if(m==12) printf("%02d December, %d",d,y);
        }

        else if(p==3){
            if(m==1) printf("January %02d, %d",d,y);
            else if(m==2) printf("February %02d, %d",d,y);
            else if(m==3) printf("March %02d, %d",d,y);
            else if(m==4) printf("April %02d, %d",d,y);
            else if(m==5) printf("May %02d, %d",d,y);
            else if(m==6) printf("June %02d, %d",d,y);
            else if(m==7) printf("July %02d, %d",d,y);
            else if(m==8) printf("August %02d, %d",d,y);
            else if(m==9) printf("September %02d, %d",d,y);
            else if(m==10) printf("October %02d, %d",d,y);
            else if(m==11) printf("November %02d, %d",d,y);
            else if(m==12) printf("December %02d, %d",d,y);
        }

        else if(p==4){
            if(m==1) printf("%02d January, %02d",d,y);
            else if(m==2) printf("%02d February, %02d",d,y);
            else if(m==3) printf("%02d March, %02d",d,y);
            else if(m==4) printf("%02d April, %02d",d,y);
            else if(m==5) printf("%02d May, %02d",d,y);
            else if(m==6) printf("%02d June, %02d",d,y);
            else if(m==7) printf("%02d July, %02d",d,y);
            else if(m==8) printf("%02d August, %02d",d,y);
            else if(m==9) printf("%02d September, %02d",d,y);
            else if(m==10) printf("%02d October, %02d",d,y);
            else if(m==11) printf("%02d November, %02d",d,y);
            else if(m==12) printf("%02d December, %02d",d,y);
        }



    }

return 0;
}
