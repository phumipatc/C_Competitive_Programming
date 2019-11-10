/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[1100],str2[1100],temp[1100];
int main(){
    int m,countt=0,len,l,r;
    cin >> m >> str;
    strcpy(str2,str);
    len=strlen(str);
    while(strcmp(str,str2)!=0 || countt==0){
        countt++;
        l=0,r=len-1;
        for(int i=0;i<len;i++){
            if(i%2==0)
                temp[i]=str2[l++];
            else
                temp[i]=str2[r--];
        }
        strcpy(str2,temp);
    }
    m%=countt;
    while(m--){
        l=0,r=len-1;
        for(int i=0;i<len;i++){
            if(i%2==0)
                temp[l++]=str[i];
            else
                temp[r--]=str[i];
        }
        strcpy(str,temp);
    }
    cout << str << endl;
    return 0;
}
