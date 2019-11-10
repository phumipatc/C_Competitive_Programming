/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include <stdio.h>
#include <string.h>
int bee[105];
char a[20][20];
int main()
{
    int n,m,k,i,j,nowi,nowj,nowt,count=0,oldi,oldj;
    scanf("%d %d %d",&n,&m,&k);
    memset(a,' ',sizeof a);
    for(i=0;i<k;i++)
        scanf("%d",&bee[i]);
    if(bee[0]==1){
        printf("0\n");
        a[n-1][m-1]='x';
        for(i=0;i<2*n+1;i++){
            if(i%2==0){
                for(j=0;j<2*m+1;j++)
                    printf(".");
                printf("\n");
            }
            else{
                for(j=0;j<m;j++)
                    printf(".%c",a[i/2][j]);
                printf(".\n");
            }
        }
        return 0;
    }
    nowi=n-1,nowj=m-1,nowt=1,i=0;
    while(1){
        if(i<k && bee[i]==nowt){
            a[nowi][nowj]='x'; count--; nowi=oldi; nowj=oldj;  i++;
            continue;
        }
        oldi=nowi,oldj=nowj;
        if(nowi-1>=0 && a[nowi-1][nowj]==' '){
            a[nowi][nowj]='o';  nowi=nowi-1;  count++;  nowt++;
        }
        else if(nowj-1>=0 && a[nowi][nowj-1]==' '){
            a[nowi][nowj]='o';  nowj=nowj-1;  count++;  nowt++;
        }
        else if(nowi+1<n && a[nowi+1][nowj]==' '){
            a[nowi][nowj]='o';  nowi=nowi+1;  count++;  nowt++;
        }
        else if(nowj+1<m && a[nowi][nowj+1]==' '){
            a[nowi][nowj]='o';  nowj=nowj+1;  count++;  nowt++;
        }
        else{
            a[nowi][nowj]='h';
            printf("%d\n",count+1);
            for(i=0;i<2*n+1;i++){
                if(i%2==0){
                    for(j=0;j<2*m+1;j++)
                        printf(".");
                    printf("\n");
                }
                else{
                    for(j=0;j<m;j++)
                        printf(".%c",a[i/2][j]);
                    printf(".\n");
                }
            }
            return 0;
        }
    }
    return 0;
}
