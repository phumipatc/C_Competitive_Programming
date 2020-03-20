/*
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int l[200010][2],r[200010][2];
char str[200010],temp[100010];
int main(){
    int n;
    scanf("%d %s",&n,temp);
    strcpy(str,temp);
    strcat(str,temp);
    for(int i=1;i<=2*n;i++){
        if(str[i-1] == 'r'){
            l[i][0] = l[i-1][0]+1;
            l[i][1] = 0;
        }else if(str[i-1] == 'b'){
            l[i][1] = l[i-1][1]+1;
            l[i][0] = 0;
        }else if(str[i-1] == 'w'){
            l[i][0] = l[i-1][0]+1;
            l[i][1] = l[i-1][1]+1;
        }
    }
    for(int i=2*n-1;i>=0;i--){
        if(str[i] == 'r'){
            r[i][0] = r[i+1][0]+1;
            r[i][1] = 0;
        }else if(str[i] == 'b'){
            r[i][1] = r[i+1][1]+1;
            r[i][0] = 0;
        }else if(str[i] == 'w'){
            r[i][0] = r[i+1][0]+1;
            r[i][1] = r[i+1][1]+1;
        }
    }
    int ans = -1e9;
    for(int i=0;i<2*n;i++)
        ans = max(ans,max(l[i][0],l[i][1])+max(r[i][0],r[i][1]));
    printf("%d\n",min(ans,n));
	return 0;
}
