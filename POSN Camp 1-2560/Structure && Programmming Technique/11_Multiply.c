#include<stdio.h>
#include<string.h>
char a[200000],b[200000],temp[200000];
int c[200000];
int main(){
    int ch1=0,ch2=0,lena,lenb,i,j,k;
    scanf(" %s",temp);
    if(temp[0]=='0'){
        printf("0\n");
        return 0;
    }
    if(temp[0]=='-'){
        strcpy(a,&temp[1]);
        ch1=1;
    }else{
        strcpy(a,temp);
    }
    scanf(" %s",temp);
    if(temp[0]=='0'){
        printf("0\n");
        return 0;
    }
    if(temp[0]=='-'){
        strcpy(b,&temp[1]);
        ch2=1;
    }else{
        strcpy(b,temp);
    }
    if(ch1!=ch2){
        printf("-");
    }
    lena = strlen(a);
    lenb = strlen(b);
    for(i=lena-1;i>=0;i--){
        for(j=lenb-1,k=lena-1-i;j>=0;j--){
            int tem = (a[i]-'0') * (b[j]-'0')+c[k],p=k;
            c[p] = tem%10;
            c[p+1] += tem/10;
            k=p+1;
        }
    }
    for(i=(c[k])?k:k-1;i>=0;i--){
        printf("%d",c[i]);
    }
    printf("\n");
}
