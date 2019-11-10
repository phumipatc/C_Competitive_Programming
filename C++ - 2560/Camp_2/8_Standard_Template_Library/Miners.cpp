/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<stdio.h>
#include<string.h>
#define Max(a,b) ((a>b)?a:b)
int mic[2][16][16],z[13]={0,1,2,3,5,6,7,9,10,11,13,14,15};
int f(char x)
{
    switch(x){
        case 'M': return 1;
        case 'F': return 2;
        case 'B': return 3;
    }
}
int g(int a,int b,int c)
{
    if(a==0){
        if(b==0) return 1;
        if(b==c) return 1;
        return 2;
    }
    if(a==b&&b==c) return 1;
    if(a==b||b==c||c==a) return 2;
    return 3;
}
int main()
{
    int n,i,j,k,x,ans=0;
    char ch;
    scanf("%d\n",&n);
    memset(mic[0],-1,sizeof(mic[0]));
    scanf("%c",&ch);
    mic[0][f(ch)][0]=1;
    for(i=1;i<n;i++){
        scanf("%c",&ch);
        x=f(ch);
        for(j=1;j<13;j++){
            for(k=0;k<13;k++){
                mic[i%2][z[j]][z[k]]=mic[(i+1)%2][z[j]][z[k]];
            }
        }
        for(j=1;j<13;j++){
            for(k=0;k<13;k++){
                if(mic[(i+1)%2][z[j]][z[k]]!=-1){
                    mic[i%2][z[j]%4*4+x][z[k]]=Max(mic[i%2][z[j]%4*4+x][z[k]],mic[(i+1)%2][z[j]][z[k]]+g(z[j]/4,z[j]%4,x));
                    mic[i%2][z[j]][z[k]%4*4+x]=Max(mic[i%2][z[j]][z[k]%4*4+x],mic[(i+1)%2][z[j]][z[k]]+g(z[k]/4,z[k]%4,x));
                }
            }
        }
//        for(j=1;j<=13;j++){
//            for(k=0;k<13;k++){
//                printf("%d ",mic[i][z[j]][z[k]]);
//            }printf("\n");
//        }printf("\n");
    }
    for(j=1;j<=13;j++){
        for(k=0;k<13;k++){
            ans=Max(ans,mic[(n-1)%2][z[j]][z[k]]);
        }
    }printf("%d\n",ans);
    return 0;
}
