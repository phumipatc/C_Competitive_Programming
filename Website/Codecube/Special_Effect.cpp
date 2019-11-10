/*
    Task    :
    Author  : Phumipat C.
    School  : RYW
    Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
char str[90][90],ans[90][90];
int main(){
    int n,m,k;
    cin >> m >> n;
    for(int i=1;i<=n;i++)
        cin >> str[i]+1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(ans[i][j] == NULL)   ans[i][j] = str[i][j];
            if(str[i][j] == 'B')    ans[i][j] = '*';
            if(str[i][j] == 'V'){
                k = i+1;
                while(k<=n){
                    if(str[k][j]!='.')  break;
                    if(ans[k][j] == NULL)       ans[k][j] = '|';
                    else if(ans[k][j] == '-')   ans[k][j] = '+';
                    k++;
                }
            }
            if(str[i][j] == '^'){
                k = i-1;
                while(k>=1){
                    if(str[k][j]!='.')  break;
                    if(ans[k][j] == NULL || ans[k][j] == '.')   ans[k][j] = '|';
                    else if(ans[k][j] == '-')                   ans[k][j] = '+';
                    k--;
                }
            }
            if(str[i][j] == '>'){
                k = j+1;
                while(k<=m){
                    if(str[i][k]!='.')  break;
                    if(ans[i][k] == NULL)       ans[i][k] = '-';
                    else if(ans[i][k] == '|')   ans[i][k] = '+';
                    k++;
                }
            }
            if(str[i][j] == '<'){
                k = j-1;
                while(k>=1){
                    if(str[i][k]!='.')  break;
                    if(ans[i][k] == NULL || ans[i][k] == '.')   ans[i][k] = '-';
                    else if(ans[i][k] == '|')                   ans[i][k] = '+';
                    k--;
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
        printf("%s\n",ans[i]+1);
    return 0;
}
