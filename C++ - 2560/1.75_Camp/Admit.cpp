/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include <bits/stdc++.h>
using namespace std;
char a[110][30],b[100100];
int mic[100100];
int main(){
    int n,i,lenb,j,len,ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf(" %s",a[i]);
    scanf(" %s",b+1);
    mic[0]=1;
    lenb = strlen(b+1);
    for(i=1;i<=lenb;i++){
        for(j=0;j<n;j++){
            len = strlen(a[j]);
            if(len>i)  continue;
            if(!strncmp(&b[i-len+1],a[j],len)){
                mic[i]=mic[i-len];
                if(mic[i]==1)
                break;
            }
        }
    }
    for(i=1;i<=lenb;i++)
        if(mic[i]==1)
            ans=i;
    printf("%d\n",ans);
    return 0;
}
/*
5 A AB BBC CA BA ABABACABAABCB
5
A AB BBC CA BA
ABABACABAABABBCAC
*/
