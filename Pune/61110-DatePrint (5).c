#include<stdio.h>
char str[15];
int main(){
    int n,i,d,p,y,m,py;
    char pm;
    scanf("%d",&n);
    while(n--){
        scanf("%s",str);
        d = ((str[0]-'0')*10)+(str[1]-'0');
        m = ((str[3]-'0')*10)+(str[4]-'0');
        y = ((str[6]-'0')*1000)+((str[7]-'0')*100)+((str[8]-'0')*10)+(str[9]-'0');
        if(d<1 || d>31 || m<1 || m>12 || y<1000 || y>3000 || p<1 || p>4 || str[2]!='/') printf("No\n");
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
            py=y%100;
            if(m==1) printf("%02d January, %d",d,py);
            else if(m==2) printf("%02d February, %d",d,py);
            else if(m==3) printf("%02d March, %d",d,py);
            else if(m==4) printf("%02d April, %d",d,py);
            else if(m==5) printf("%02d May, %d",d,py);
            else if(m==6) printf("%02d June, %d",d,py);
            else if(m==7) printf("%02d July, %d",d,py);
            else if(m==8) printf("%02d August, %d",d,py);
            else if(m==9) printf("%02d September, %d",d,py);
            else if(m==10) printf("%02d October, %d",d,py);
            else if(m==11) printf("%02d November, %d",d,py);
            else if(m==12) printf("%02d December, %d",d,py);
        }
    }

return 0;
}
