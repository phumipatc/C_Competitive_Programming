/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[100005];
int main(){
    int q,temp,len,ans;
    scanf("%d",&q);
    while(q--){
        scanf(" %s",str+1);
        len=strlen(str+1);
        if(len == 1 && str[1] == 0){
            printf("4\n");
            continue;
        }
        ans = 1;
        temp = 0;
        for(int i=1;i<=len;i++){
            temp = (temp*10)+(str[i]-'0');
            temp%=4;
        }
        switch(temp){
            case 0 : ans+=1;    break;
            case 1 : ans+=2;    break;
            case 2 : ans+=4;    break;
            case 3 : ans+=3;    break;
        }
//        printf("%d\n",ans);
        temp = 0;
        for(int i=1;i<=len;i++){
            temp = (temp*10)+(str[i]-'0');
            temp%=4;
        }
        switch(temp){
            case 0 : ans+=1;    break;
            case 1 : ans+=3;    break;
            case 2 : ans+=4;    break;
            case 3 : ans+=2;    break;
        }
//        printf("%d\n",ans);
        temp = 0;
        for(int i=1;i<=len;i++){
            temp = (temp*10)+(str[i]-'0');
            temp%=2;
        }
        switch(temp){
            case 0 : ans+=1;    break;
            case 1 : ans+=4;    break;
        }
        printf("%d\n",ans%5);
    }
    return 0;
}
