/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[1005][1000005],num[1005],mark[1005];
int main(){
    int n,idx = 0,ans = 1e9,sum;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf(" %s",str[i]),mark[i] = 1;
    scanf(" %s",num);
    int len = strlen(num);
    for(int i=0;i<len;i++){
        sum = 0;
        for(int j=0;j<n;j++){
            str[j][idx] = tolower(str[j][idx]);
            if(num[i] == '2'){
                if(!mark[j])    continue;
                if(str[j][idx] == 'a' || str[j][idx] == 'b' || str[j][idx] == 'c')
                    sum++;
                else
                    mark[j] = 0;
            }else if(num[i] == '3'){
                if(!mark[j])    continue;
                if(str[j][idx] == 'd' || str[j][idx] == 'e' || str[j][idx] == 'f')
                    sum++;
                else
                    mark[j] = 0;
            }else if(num[i] == '4'){
                if(!mark[j])    continue;
                if(str[j][idx] == 'g' || str[j][idx] == 'h' || str[j][idx] == 'i')
                    sum++;
                else
                    mark[j] = 0;
            }else if(num[i] == '5'){
                if(!mark[j])    continue;
                if(str[j][idx] == 'j' || str[j][idx] == 'k' || str[j][idx] == 'l')
                    sum++;
                else
                    mark[j] = 0;
            }else if(num[i] == '6'){
                if(!mark[j])    continue;
                if(str[j][idx] == 'm' || str[j][idx] == 'n' || str[j][idx] == 'o')
                    sum++;
                else
                    mark[j] = 0;
            }else if(num[i] == '7'){
                if(!mark[j])    continue;
                if(str[j][idx] == 'p' || str[j][idx] == 'q' || str[j][idx] == 'r' || str[j][idx] == 's')
                    sum++;
                else
                    mark[j] = 0;
            }else if(num[i] == '8'){
                if(!mark[j])    continue;
                if(str[j][idx] == 't' || str[j][idx] == 'u' || str[j][idx] == 'v')
                    sum++;
                else
                    mark[j] = 0;
            }else if(num[i] == '9'){
                if(!mark[j])    continue;
                if(str[j][idx] == 'w' || str[j][idx] == 'x' || str[j][idx] == 'y' || str[j][idx] == 'z')
                    sum++;
                else
                    mark[j] = 0;
            }
        }
        ans = min(ans,sum);
        idx++;
    }
    printf("%d\n",ans);
    return 0;
}
