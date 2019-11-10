/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[20],b[10];
int main()
{
    int n,i,len,now=1,num,k,ans,x;
    scanf("%d",&n);
    for(x=1,k=0;x<=n;x++,k=0){
        scanf(" %s",a);
        len=strlen(a);
        if(len==16){
            for(i=0;i<len-1;i+=2){
//                printf("%c %c %d %d\n",a[i],a[i+1],now,i);
                if(now==1){
                    if(a[i]=='1' && a[i+1]=='1'){
                        b[k++]='1';
                        now=2;
                    }else{
                        b[k++]='0';
                        now=1;
                    }
                }else if(now==2){
                    if(a[i]=='0' && a[i+1]=='1'){
                        b[k++]='1';
                        now=4;
                    }else{
                        b[k++]='0';
                        now=3;
                    }
                }else if(now==3){
                    if(a[i]=='0' && a[i+1]=='0'){
                        b[k++]='1';
                        now=2;
                    }else{
                        b[k++]='0';
                        now=1;
                    }
                }else if(now==4){
                    if(a[i]=='0' && a[i+1]=='1'){
                        b[k++]='0';
                        now=3;
                    }else{
                        b[k++]='1';
                        now=4;
                    }
                }
            }
            for(i=7,ans=0;i>=0;i--){
                ans+=(b[i]-'0')*pow(2,7-i);
            }
            printf("%c",ans);
        }
    }
    return 0;
}
/*
3
0011100010000110
0100100010001000
1011

4
0011101100000011
1000101100001110
1111101100001101
0100101100111011
*/
