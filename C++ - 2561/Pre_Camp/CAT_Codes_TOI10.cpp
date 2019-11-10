/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C
*/
#include<stdio.h>
#define hashsize 500009
char a[1000100];
int hashh[hashsize],num[100100],mark[100100];
int main(){
    int k,m,i,j,sum,h,now,q,len,n,ch;
    scanf("%d %d",&k,&m);
    for(i=1;i<=k;i++){
        scanf(" %s",a);
        
        sum = a[0]-'0';
        for(j=1;j<m;j++){
            sum <<= 1;
            sum += a[j]-'0';
        }
        
        h = sum;
        h %= hashsize;
        now = 1;
        while(hashh[h]!=0){
            h += now;
            now <<= 1;
            h %= hashsize;
        }
        hashh[h] = i;
        num[i] = sum;

    }
    scanf("%d",&q);
    for(i=1;i<=q;i++){
        scanf("%d %s",&len,a);
        ch = 0;
        if(len<m){
            printf("OK\n");
            continue;
        }
        sum = a[0]-'0';
        for(j=1;j<m-1;j++){
            sum <<= 1;
            sum += a[j]-'0';
        }

        for(j=m-1;j<len;j++){
            sum <<= 1;
            sum += a[j]-'0';
            sum &= ((1<<m)-1); // cut

            h = sum;
            h %= hashsize;
            now = 1;
            while(hashh[h]!=0){
                if(num[ hashh[h] ]==sum){
                    mark[hashh[h]]=i;
                    ch=1;
                    break;
                }
                h += now;
                now <<= 1;
                h %= hashsize;
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
