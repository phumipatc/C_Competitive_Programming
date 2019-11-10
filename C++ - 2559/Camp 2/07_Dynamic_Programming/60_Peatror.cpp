/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[10]={1};
char a[1000100];
int main(){
    int lena,i;
    scanf(" %s",a);
    lena=strlen(a);
    for(i=0;i<lena;i++){
        if(a[i]=='p')
            mic[1]+=mic[0]%2555;
        if(a[i]=='e')
            mic[2]+=mic[1]%2555;
        if(a[i]=='a')
            mic[3]+=mic[2]%2555;
        if(a[i]=='t')
            mic[4]+=mic[3]%2555;
        if(a[i]=='r'){
            mic[5]+=mic[4]%2555;
            mic[7]+=mic[6]%2555;
        }
        if(a[i]=='o')
            mic[6]+=mic[5]%2555;
    }
    printf("%d\n",mic[7]%2555);
return 0;
}
