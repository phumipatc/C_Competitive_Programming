#include<bits/stdc++.h>
using namespace std;
char a[1000100],b[1000100];
int ans[1000100];
int main()
{
    int i,len,k=0;
    scanf(" %s %s",a,b);
    len=strlen(a);
    for(i=0;i<len;i++){
        if(tolower(a[i])-tolower(b[i])>=0){
            ans[k++]=tolower(a[i])-tolower(b[i]);
        }else{
            ans[k++]=tolower(a[i])+26-tolower(b[i]);
        }
        if(ans[k-1]>9){
            printf("R.I.P.\n");
            return 0;
        }
    }
    for(i=0;i<len;i++)
        printf("%d",ans[i]);
    return 0;
}
