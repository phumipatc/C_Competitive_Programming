/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
int mic[300][300][3];
char str[500];
int main(){
    int n,q=20;
    while(q--){
        scanf("%d",&n);
        scanf(" %s",str+1);
        for(int i = 1 ; i <= n ; i++)
            mic[i][i][str[i]-'0']=1;
        for(int len=2;len<=n;len++){
            for(int i=1;i<=n-len+1;i++){
                for(int mid=i;mid<i+len-1;mid++){
                    for(int ch1=0;ch1<=2;ch1++){
                        for(int ch2=0;ch2<=2;ch2++){
                            if(mic[i][mid][ch1]==1 && mic[mid+1][i+len-1][ch2]==1){
                                if(ch1==0){
                                    if(ch2==0)
                                        mic[i][i+len-1][2] = 1;
                                    if(ch2 == 1)
                                        mic[i][i+len-1][1] = 1;
                                    if(ch2 == 2)
                                        mic[i][i+len-1][0] = 1;
                                }
                                if(ch1 == 1){
                                    if(ch2 == 0)
                                        mic[i][i+len-1][2] = 1;
                                    if(ch2 == 1)
                                        mic[i][i+len-1][1] = 1;
                                    if(ch2 == 2)
                                        mic[i][i+len-1][1] = 1;
                                }
                                if(ch1 == 2){
                                    if(ch2 == 0)
                                        mic[i][i+len-1][1] = 1;
                                    if(ch2 == 1)
                                        mic[i][i+len-1][2] = 1;
                                    if(ch2 == 2)
                                        mic[i][i+len-1][1] = 1;
                                }
                            }
                        }
                    }
                }
            }
        }
        if(mic[1][n][0]==1)
            printf("yes\n");
        else
            printf("no\n");
        memset(mic,0,sizeof mic);
    }
}
