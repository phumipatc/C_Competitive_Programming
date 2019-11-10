/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
int binary[50];
int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int ch=0,i,j;
        long long n;
        scanf("%lld",&n);
        if(n==0){
            printf("n\n");
            continue;
        }
        memset(binary,0,sizeof binary);
        if(n<0) ch=1;
        n=abs(n);
        for(i=32;i>0;i--)
            if(n&((long long)1<<(i-1)))
                binary[i-1]=1;
        for(i=0;i<=32;i++){
            if(binary[i]==1){
                if(binary[i+1]==1){
                    binary[i]=-1;
                    binary[i+1]=0;
                    binary[i+2]++;
                }
            }else if(binary[i]==2){
                binary[i]=0;
                binary[i+1]++;
            }
        }
        for(i=32;i>=0;i--)
            if(binary[i]!=0)
                break;
        for(j=i;j>=0;j--){
            if(ch){
                if(binary[j]==-1)       printf("p");
                else if(binary[j]==0)   printf("n");
                else                    printf("e");
            }else{
                if(binary[j]==-1)       printf("e");
                else if(binary[j]==0)   printf("n");
                else                    printf("p");
            }
        }
        printf("\n");
    }
    return 0;
}
