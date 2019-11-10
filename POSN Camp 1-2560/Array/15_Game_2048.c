#include<stdio.h>
#include<string.h>
int a[30][30],mark[30][30];
char command[10];
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    scanf(" %s",command);
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            scanf("%d",&a[i][j]);
    if(command[0] == 'r')
    {
        for(j=n-2; j>=0; j--)
            for(i=0; i<n; i++)
            {
                if(a[i][j]!=0)
                {

                    for(k=j+1; k<n; k++)
                        if(a[i][k]==0)
                        {
                            a[i][k]=a[i][k-1];
                            a[i][k-1]=0;
                        }
                        else if(a[i][k]==a[i][k-1]&&!mark[i][k])
                        {
                            mark[i][k] = 1;
                            a[i][k]*=2;
                            a[i][k-1]=0;
                            break;
                        }
                        else break;
                }
            }
    }
    else if(command[0] == 'l')
    {
        for(j=1; j<n; j++)
            for(i=0; i<n; i++)
            {
                if(a[i][j]!=0)
                    for(k = j-1; k>=0; k--)
                        if(a[i][k]==0)
                        {
                            a[i][k] = a[i][k+1];
                            a[i][k+1] = 0;
                        }
                        else if(a[i][k]==a[i][k+1]&&!mark[i][k])
                        {
                            mark[i][k] = 1;
                            a[i][k] *=2;
                            a[i][k+1] = 0;
                            break;
                        }
                        else break;
            }
    }
    else if(command[0]=='u')
    {
        for(i=1; i<n; i++)
            for(j=0; j<n; j++)
                if(a[i][j]!=0)
                    for(k=i-1; k>=0; k--)
                        if(a[k][j]==0)
                        {
                            a[k][j]=a[k+1][j];
                            a[k+1][j] = 0;
                        }
                        else if(a[k][j]==a[k+1][j]&&!mark[k][j])
                        {
                            mark[k][j]=1;
                            a[k][j]*=2;
                            a[k+1][j]=0;
                            break;
                        }
                        else break;
    }
    else if(command[0]=='d')
        for(i=n-2; i>=0; i--)
            for(j=0; j<n; j++)
                if(a[i][j]!=0)
                    for(k=i+1; k<n; k++)
                        if(a[k][j]==0)
                        {
                            a[k][j]=a[k-1][j];
                            a[k-1][j]=0;
                        }
                        else if(a[k][j]==a[k-1][j]&&!mark[k][j])
                        {
                            mark[k][j]=1;
                            a[k][j]*=2;
                            a[k-1][j]=0;
                            break;
                        }
                        else break;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }


    return 0;
}
/*
 4
 right
 2 0 2 4
 2 0 4 2
 2 2 4 8
 2 2 4 4

 4
 up
 2 0 2 4
 2 0 4 2
 2 2 4 8
 2 2 4 4

 4
 left
 2 0 2 4
 2 0 4 2
 2 2 4 8
 2 2 4 4

 4
 down
 2 0 2 4
 2 0 4 2
 2 2 4 8
 2 2 4 4
 */
