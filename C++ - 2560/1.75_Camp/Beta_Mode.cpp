/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<bits/stdc++.h>
using namespace std;
int mic[2][1100];
char a[10100],b[10100];
int main()
{
    int i,j,lena,lenb,maxx=0,start=0;
    scanf(" %s %s",a,b);
    lena=strlen(a),lenb=strlen(b);
    for(i=0;i<lena;i++){
        for(j=0;j<lenb;j++){
            if(a[i]!=b[j])  mic[i%2][j]=0;
            else{
                mic[i%2][j]=mic[(i+1)%2][j-1]+1;
                if(mic[i%2][j]>maxx){
                    maxx=mic[i%2][j];
                    start=i;
                }
            }
        }
    }
    for(i=start-maxx+1;i<=start;i++)
        printf("%c",a[i]);
    return 0;
}
