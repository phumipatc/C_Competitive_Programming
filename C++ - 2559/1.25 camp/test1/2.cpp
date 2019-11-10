/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<stdio.h>
char a[1200][1200];
int main()
{
    int x,y,i,j,ch,ch0=0,ch1=0,ch2=0,ch3=0,ch4=0;
    scanf("%d %d",&x,&y);
    for(i=0;i<(5*x)+1;i++){
        for(j=0;j<(5*y)+1;j++){
            scanf(" %c",&a[i][j]);
        }
    }
    for(i=1;i<(5*x)+1;i+=5){
        for(j=1;j<(5*y)+1;j+=5){
            ch=0;
            if(a[i][j]=='*')
                ch++;
            if(a[i+1][j]=='*')
                ch++;
            if(a[i+2][j]=='*')
                ch++;
            if(a[i+3][j]=='*')
                ch++;
            if(ch==0)
                ch0++;
            else if(ch==1)
                ch1++;
            else if(ch==2)
                ch2++;
            else if(ch==3)
                ch3++;
            else if(ch==4)
                ch4++;
        }
    }
    printf("%d %d %d %d %d",ch0,ch1,ch2,ch3,ch4);
return 0;
}
/*
2 3
################
#****#****#****#
#****#****#****#
#****#....#****#
#....#....#****#
################
#....#****#****#
#....#****#....#
#....#....#....#
#....#....#....#
################
*/
