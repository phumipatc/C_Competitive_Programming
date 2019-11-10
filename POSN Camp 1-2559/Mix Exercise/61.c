/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char a[100];
int b[100];
int main()
{
    int i,s,h,d,c,n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,n9=0,n10=0,k=0,q=0,j=0,A=0;
    for(i=0;i<51;i++){
        scanf("%d %c",&b[i],&a[i]);
        if(b[i]=='K')   k++;
        if(b[i]=='Q')   q++;
        if(b[i]=='J')   j++;
        if(a[i]=='S')   s++;
        if(a[i]=='H')   h++;
        if(a[i]=='D')   d++;
        if(a[i]=='C')   c++;
        if(b[i]==1)   n1++;
        if(b[i]==2)   n2++;
        if(b[i]==3)   n3++;
        if(b[i]==4)   n4++;
        if(b[i]==5)   n5++;
        if(b[i]==6)   n6++;
        if(b[i]==7)   n7++;
        if(b[i]==8)   n8++;
        if(b[i]==9)   n9++;
        if(b[i]==10)   n10++;
        if(n1!=4)  printf("A");
        if(n2!=4)  printf("2");
        if(n3!=4)  printf("3");
        if(n4!=4)  printf("4");
        if(n5!=4)  printf("5");
        if(n6!=4)  printf("6");
        if(n7!=4)  printf("7");
        if(n8!=4)  printf("8");
        if(n9!=4)  printf("9");
        if(n10!=4)  printf("10");
        if(k!=4)    printf("K");
        if(q!=4)    printf("Q");
        if(j!=4)    printf("J");
        if(s!=13)   printf("S");
        if(h!=13)   printf("H");
        if(d!=13)   printf("D");
        if(c!=13)   printf("C");
    }
return 0;
}
/*
2C 8C 6D 6H 8S 2S 3C 4C 4S 4D 3S 3D 2D 2H 8D 8H 10H 5C AS AD AH 5S 10S 10D 5D 3H 4H 5H 7S 7C 7H
AC QC KC KS QH QD QS KD 6C 6S KH JD 7C 9C 9S 9D 7H 7S 9H 10C
*/
