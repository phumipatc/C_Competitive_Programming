/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[2][10010];
char a[10010],b[10010];
int main(){
    int i,j,ma=0,st,lena,lenb;
    scanf("%s %s",&a[1],&b[1]);
    lena=strlen(a+1);
    lenb=strlen(b+1);
    for(i=1;i<=lena;i++){
        for(j=1;j<=lenb;j++){
            if(a[i]==b[j]){
                mic[i%2][j]=mic[(i-1)%2][j-1]+1;
                if(mic[i%2][j]>ma){
                    ma=mic[i%2][j];
                    st=i-ma+1;
                }
            }else{
                mic[i%2][j]=0;
            }
        }
    }
    for(i=st;i<=ma+st-1;i++){
        printf("%c",a[i]);
    }
return 0;
}
