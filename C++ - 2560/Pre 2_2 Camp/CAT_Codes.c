/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C
*/
#include<stdio.h>
#define hashsize 500009
char a[1000100];
int mic[hashsize],code[100100],mark[100100];
int main(){
    int k,m,i,j,sum,temp,now,q,len,n,ch;
    scanf("%d %d",&k,&m);
    for(i=0;i<k;i++){
        scanf(" %s",a);
        sum=a[0]-'0';
        for(j=1;j<m;j++){
            sum <<= 1;
            sum += a[j]-'0';
        }
        temp = sum;
        temp %= hashsize;
        now = 1;
        while(mic[temp]!=0){
            temp += now;
            now <<= 1;
            temp %= hashsize;
        }
        mic[temp] = i+1;
        code[i+1] = sum;
    }
    scanf("%d",&q);
    for(i=1;i<=q;i++){
        scanf("%d",&len);
        scanf(" %s",a);
        ch=0;
        if(len<m){
            printf("OK\n");
            continue;
        }
        sum=a[0]-'0';
        for(j=1;j<m-1;j++){
            sum <<= 1;
            sum += a[j]-'0';
        }
        for(j=m-1;j<len;j++){
            sum <<= 1;
            sum += a[j]-'0';
            sum &= ((1<<m)-1); // cut
            temp = sum;
            temp %= hashsize;
            now = 1;
            while(mic[temp]!=0){
                if(code[ mic[temp] ]==sum){
                    mark[mic[temp]]=i;
                    ch=1;
                    break;
                }
                temp += now;
                now <<= 1;
                temp %= hashsize;
            }
        }
        if(!ch)
            printf("OK\n");
        else{
            for(j=1;j<=k;j++)
                if(mark[j]==i)
                    printf("%d ",j);
            printf("\n");
        }
    }
    return 0;
}
/*
10 1
-10000
9999
-9998
-9997
9996
-9995
9994
-9993
9992
-9991
*/
