/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[1100],str2[1100],test[2100];
int mic[1100][1100];
int main(){
    int q,lena,lenb;
    scanf(" %s %s %d",str+1,str2+1,&q);
    lena=strlen(str+1);
    lenb=strlen(str2+1);
    while(q--){
        scanf(" %s",test+1);
        mic[0][0]=1;
        for(int i=0;i<=lena;i++){
            for(int j=0;j<=lenb;j++){
                if(i!=0 && mic[i-1][j] && str[i]==test[i+j])    mic[i][j]=1;
                if(j!=0 && mic[i][j-1] && str2[j]==test[i+j])   mic[i][j]=1;
            }
        }
        if(mic[lena][lenb]) printf("Yes\n");
        else                printf("No\n");
        memset(mic,0,sizeof mic);
    }
    return 0;
}
