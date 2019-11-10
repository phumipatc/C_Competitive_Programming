/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[110],num[15];
int main(){
    int n,i,d,len,j;
    scanf(" %s %d",a,&n);
    for(i=0;i<n;i++){
        scanf("%d",&d);
        num[d]=1;
    }
    len=strlen(a);
    while(1){
        for(i=0;i<len;i++){
            printf("%d\n",a[i]-'0');
            if(i==len-1 && num[a[i]-'0']==0) goto next;
            if(num[a[i]-'0']==1){
                if(a[i]-'0'==0){
                    a[i]='9';
                }else{
                    a[i]--;
                }
                for(j=i+1;j<len;j++){
                    a[j]=57;
                }
            }
        }
    }
    next:{
        printf("%s",a);
    }
	return 0;
}
