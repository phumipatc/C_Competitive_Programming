/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[110];
long long temp[110],countt,t[15],ch,len,ans;
void permute(long long state){
    if(state == countt){
        long long idx = 0,num = 1,cou = 0;

        for(long long i=1;i<=len;i++){
            if(str[i] == '_')
                temp[i] = t[idx++];
            else if(str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
                temp[i] = 1;
            else
                temp[i] = 2;
            // printf("%d ",temp[i]);
        }
        // printf("\n");
        for(long long i=1;i<=len;i++){
            if(temp[i] == 1){
                if(temp[i-1] == 1 && temp[i+1] == 1)    return ;
            }else if(temp[i] == 2){
                if(temp[i-1] == 2 && temp[i+1] == 2)    return ;
                if(str[i]!='_')                         continue;
                cou = 1;
            }
        }
        if(!ch && !cou)    return ;
        if(ch){
            for(int i=0;i<countt;i++){
                if(t[i] == 1){
                    num*=5;
                }else{
                    num*=21;
                }
            }
            ans+=num;
        }else{
            for(int i=0;i<countt;i++){
                if(t[i] == 1)   continue;
                num = 1;
                for(int j=0;j<countt;j++){
                    if(t[j] == 1){
                        num*=5;
                        continue;
                    }
                    if(j<i)         num*=20;
                    else if(j>i)    num*=21;
                }
                // printf("%d %d\n",i,num);
                ans+=num;
            }
        }
        return ;
    }
    t[state] = 1;
    permute(state+1);
    t[state] = 2;
    permute(state+1);
}
int main(){
    scanf(" %s",str+1);
    len = strlen(str+1);
    for(long long i=1;i<=len;i++){
        if(str[i] == '_')
            countt++;
        if(str[i] == 'L')
            ch = 1;
    }
    permute(0);
    printf("%lld\n",ans);
	return 0;
}
