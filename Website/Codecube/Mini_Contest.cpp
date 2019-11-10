/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[120000];
int main(){
    int n,i;
    scanf("%d",&n);
    scanf(" %s",a);
    for(i=0;i<n;i++){
        if(a[i]==a[i+1]){
            printf("Wrong Answer\n");
            return 0;
        }
    }
    printf("Accepted\n");
return 0;
}
