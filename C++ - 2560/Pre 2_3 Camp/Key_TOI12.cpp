/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1100],b[1100],test[2100];
int mic[1100][1100];
int main(){
    int lena,lenb,q;
    scanf(" %s %s %d",a+1,b+1,&q);
    lena=strlen(a+1);
    lenb=strlen(b+1);
    while(q--){
        scanf(" %s",test+1);
        memset(mic,0,sizeof mic);
        mic[0][0]=1;
        for(int i=0;i<=lena;i++){
            for(int j=0;j<=lenb;j++){
                if(i!=0 && mic[i-1][j]==1 && a[i]==test[i+j])
                    mic[i][j]=1;
                if(j!=0 && mic[i][j-1]==1 && b[j]==test[i+j])
                    mic[i][j]=1;
            }
        }
        if(mic[lena][lenb]==1)  printf("Yes\n");
        else                    printf("No\n");
    }
    return 0;
}
