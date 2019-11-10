/*
    TASK:
    AUTHOR: Phumipat Chaiprasertsud
    SCHOOL:RYW
    LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010],b[1010];
int main(){
    int l,n,i,j,countt;
    scanf("%d %d %s",&l,&n,a);
    for(i=0;i<n-1;i++){
        scanf(" %s",b);
        for(j=0,countt=0;j<l;j++)
            if(a[j]!=b[j])
                countt++;
        if(countt>2)
            break;
        strcpy(a,b);
    }
    printf("%s\n",a);
    return 0;
}
