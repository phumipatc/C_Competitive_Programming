/*
    TASK :
    AUTHOR : Boss
    SCHOOL : RYW
    LANG : C++
*/
#include<bits/stdc++.h>
using namespace std;
char a[1100][1100];
int main()
{
    int i,j,x,y,k,l,ans,minn=1<<21,ati=0,atj=0;
    scanf("%d %d",&x,&y);
    for(i=1;i<=x;i++)
        scanf(" %s",&a[i][1]);
    for(i=1;i<=x;i++){
        for(j=1;j<=y;j++){
            if(a[i][j]=='X'){
                ans=0;
                k=i-1,l=j-1;
                while(a[k][j]=='v'){
                    ans++;
                    k--;
                    //printf("-\n");
                }
                while(a[i][l]=='>'){
                    ans++;
                    l--;
                    //printf("--\n");
                }
                k=i+1,l=j+1;
                while(a[k][j]=='^'){
                    ans++;
                    k++;
                    //printf("+\n");
                }
                while(a[i][l]=='<'){
                    ans++;
                    l++;
                    //printf("++\n\n");
                }
                if(ans<minn){
                    minn=ans;
                    ati=i,atj=j;
                    //printf("%d %d %d %d\n\n",ans,minn,ati,atj);
                }
            }
        }
    }
    printf("%d %d\n",ati,atj);
    return 0;
}
/*
4 10
###v####^#
###v####.#
.>>X.###v#
###^####X<

6 6
#v##v#
>X<>X<
#^##^#
#v##v#
>X<>X<
#^##^#
*/
