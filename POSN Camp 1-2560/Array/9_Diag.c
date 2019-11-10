/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C
*/
#include<stdio.h>
int a[700][700];
int main(){
    int n,m,i,j,temp;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&a[i][j]);

    j=0,i=temp=n-1;
    while(temp>=0){
        printf("%d ",a[i][j]);
        if(i+1<n && j+1<m){
            i++,j++;
        }else{
            temp--;
            i=temp,j=0;
        }
    }
    i=0,j=temp=1;
    while(temp<m){
        printf("%d ",a[i][j]);
        if(i+1<n && j+1<m){
            i++,j++;
        }else{
            temp++;
            i=0,j=temp;
        }
    }
    printf("\n");

    j=0,i=temp=0;
    while(temp<n){
        printf("%d ",a[i][j]);
        if(i-1>=0 && j+1<m){
            i--,j++;
        }else{
            temp++;
            i=temp,j=0;
        }
    }
    i=n-1,j=temp=1;
    while(temp<m){
        printf("%d ",a[i][j]);
        if(i-1>=0 && j+1<m){
            i--,j++;
        }else{
            temp++;
            i=n-1,j=temp;
        }
    }
    return 0;
}
/*
3 4
1 2 3 4
5 6 7 8
9 10 11 12

4 7
1 2 3 4 5 6 7
8 9 10 11 12 13 14
15 16 17 18 19 20 21
22 23 24 25 26 27 28
*/
