#include<stdio.h>
char a[2000],b[2000];
int c[5000],nub[20];
int main(){
    int n,i,j,k,lena,lenb,l;
    scanf("%d",&n);
    sprintf(a,"1");
    for(l=2;l<=n;l++){
        sprintf(b,"%d",l);
        lena = strlen(a);
        lenb = strlen(b);
        for(i=lena-1;i>=0;i--){
            for(j=lenb-1,k=lena-1-i;j>=0;j--,k++){
                int temp = (a[i]-'0')*(b[j]-'0')+c[k];
                c[k]=temp%10;
                c[k+1] += temp/10;
            }
        }
        for(k=4000;k>=0;k--){
            if(c[k])
                break;
        }
        for(i=0;i<=k;i++){
            a[i]=c[k-i]+'0';
        }
        a[i]='\0';
        memset(c,0,sizeof c);
    }
    printf("%s\n",a);
    lena = strlen(a);
    for(i=0;i<lena;i++)
        nub[a[i]-'0']++;
    for(i=0;i<=9;i++)
        printf("%d : %d\n",i,nub[i]);
    return 0;
}
