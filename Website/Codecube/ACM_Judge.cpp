/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[50];
int main(){
    int q,len;
    scanf("%d",&q);
    for(int j=1;j<=q;j++){
        scanf(" %s",a);
        len=strlen(a);
        int chx=0,cht=0,che=0;
        for(int i=0;i<len;i++){
            if(a[i]=='X')           chx++;
            else if(a[i]=='T')      cht++;
            else if(a[i]=='-')      che++;
        }
        if(chx!=0){
            printf("Case #%d: No - Runtime error\n",j);
        }else if(cht!=0){
            printf("Case #%d: No - Time limit exceeded\n",j);
        }else if(che!=0){
            printf("Case #%d: No - Wrong answer\n",j);
        }else{
            printf("Case #%d: Yes\n",j);
        }
    }
return 0;
}
