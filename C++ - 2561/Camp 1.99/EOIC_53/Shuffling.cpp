/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
int l[1000010],r[1000010];
char opr[100010];
int main()
{
    int m,k,len,fi,sec,en;
    scanf("%d %d %s",&m,&k,opr+1);
    len = strlen(opr+1);
    for(int i=1;i<=m;i++)
        l[i] = i-1,r[i] = i+1;
    fi = 1,sec = 2,en = m;
    for(int i=1;i<len;i++){
        if(opr[i] == 'A'){
            l[r[fi]] = l[fi];
            r[l[fi]] = r[fi];
            l[fi] = en;
            r[en] = fi;
            fi = r[fi];
            sec = r[sec];
            en = r[en];
        }else{
            l[r[sec]] = l[sec];
            r[l[sec]] = r[sec];
            l[sec] = en;
            r[en] = sec;
            sec = r[sec];
            en = r[en];
        }
    }
    int now = fi;
    for(int i=1;i<=k;i++)
        now = r[now];
    printf("%d %d %d",l[now]-1,now-1,r[now]-1);
    return 0;
}
