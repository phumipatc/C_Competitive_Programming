/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
int r,c,len;
char a[30][30],str[20];
bool up(int i,int j,int state){
    if(state == len+1)  return 1;
    if(a[i][j] == str[state])
        if(up(i-1,j,state+1))
            return 1;
    return 0;
}
bool down(int i,int j,int state){
    if(state == len+1)  return 1;
    if(a[i][j] == str[state])
        if(down(i+1,j,state+1))
            return 1;
    return 0;
}
bool left(int i,int j,int state){
    if(state == len+1)  return 1;
    if(a[i][j] == str[state])
        if(left(i,j-1,state+1))
            return 1;
    return 0;
}
bool right(int i,int j,int state){
    if(state == len+1)  return 1;
    if(a[i][j] == str[state])
        if(right(i,j+1,state+1))
            return 1;
    return 0;
}
bool upleft(int i,int j,int state){
    if(state == len+1)  return 1;
    if(a[i][j] == str[state])
        if(upleft(i-1,j-1,state+1))
            return 1;
    return 0;
}
bool upright(int i,int j,int state){
    if(state == len+1)  return 1;
    if(a[i][j] == str[state])
        if(upright(i-1,j+1,state+1))
            return 1;
    return 0;
}
bool downleft(int i,int j,int state){
    if(state == len+1)  return 1;
    if(a[i][j] == str[state])
        if(downleft(i+1,j-1,state+1))
            return 1;
    return 0;
}
bool downright(int i,int j,int state){
    if(state == len+1)  return 1;
    if(a[i][j] == str[state])
        if(downright(i+1,j+1,state+1))
            return 1;
    return 0;
}
int main(){
    cin >> r >> c;
    for(int i=1;i<=r;i++){
        scanf(" %s",a[i]+1);
        for(int j=1;j<=c;j++)
            a[i][j] = tolower(a[i][j]);
    }
    int q,ch;
    cin >> q;
    while(q--){
        scanf(" %s",str+1);
        len = strlen(str+1);
        for(int i=1;i<=len;i++)
            str[i] = tolower(str[i]);
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                if(a[i][j] == str[1]){
                    ch = 0;
                    ch |= up(i-1,j,2);
                    ch |= down(i+1,j,2);
                    ch |= right(i,j+1,2);
                    ch |= left(i,j-1,2);
                    ch |= upleft(i-1,j-1,2);
                    ch |= upright(i-1,j+1,2);
                    ch |= downleft(i+1,j-1,2);
                    ch |= downright(i+1,j+1,2);
                    if(ch){
                        printf("%d %d\n",i-1,j-1);
                        goto next;
                    }
                }
            }
        }
        next:;
    }
	return 0;
}
