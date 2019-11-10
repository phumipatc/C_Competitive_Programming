/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[110];
int main(){
    int n,l1,r1,l2,r2,len;
    scanf("%d",&n);
    while(n--){
        scanf(" %s",str);
        len = strlen(str);
        l1 = r1 = l2 = r2 = -1;
        for(int i=0;i<len;i++){
            if(r1!=-1 && !(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'))
                break;
            if(l1 == -1 && (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'))
                l1 = i,r1 = i;
            else if(l1!=-1 && (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'))
                r1 = i;
        }
        for(int i=len-1;i>=0;i--){
            if(l2!=-1 && !(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'))
                break;
            if(r2 == -1 && (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'))
                r2 = i,l2 = i;
            else if(r2!=-1 && (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'))
                l2 = i;
        }
        for(int i=0;i<len;i++){
            if(l1<=i && i<=r1){
                for(int j=l2;j<=r2;j++) printf("%c",str[j]);
                i = r1;
                continue;
            }
            if(l2<=i && i<=r2){
                for(int j=l1;j<=r1;j++) printf("%c",str[j]);

                i = r2;
                continue;
            }
            printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}
