/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[10000010];
int four[10000010];
int main(){
    int n,i,sum = 0,mod;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&four[i]);
    for(i=0;i<n;i++){
        scanf("%d",&mod);
        if(a[four[i]] == 1) a[four[i]] = 0,sum--;
        else                a[four[i]] = 1,sum++;
        if(a[mod] == 1) a[mod] = 0,sum--;
        else            a[mod] = 1,sum++;
        if(sum == 0){
            printf("%d",i+1);
            break;
        }
    }
    return 0;
}
