#include<stdio.h>
#include<string.h>
char a[1000][120],b[120000],c[120000];
int main(){
    int n,k,p,i,j,x=0,row,lenc;
    scanf("%d %d %d",&n,&k,&p);
    scanf(" %s",b);
    row=n/k;
    if(n%k!=0){
        row+=1;
    }
    for(i=0;i<row;i++){
        for(j=0;j<k;j++){
            a[i][j]=b[x++];
        }
    }
    x=0;
    for(j=0;j<k;j++){
        for(i=0;i<row;i++){
            if(a[i][j]!=NULL){
                printf("%c",a[i][j]);
                c[x++]=a[i][j];
            }
        }
    }
    lenc=strlen(c);
    printf("\n");
    for(i=0;i<lenc;i++){
        if(c[i]+p>90 && c[i]<=90)
            c[i]-=26;
        if(c[i]+p>122)
            c[i]-=26;
        c[i]+=p;
    }
    for(i=0;i<lenc;i++){
        printf("%c",c[i]);
    }
    return 0;
}
