/*
	Task :
	Author : Phumipat C.
	School : RYW
	Language :C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main()
{
    int m,k,len,i,temp;
    char cmd[100100];
    scanf("%d %d %s",&m,&k,&cmd);
    for(i=0;i<m;i++)
        v.push_back(i);
    len=strlen(cmd);
    len--;
    for(i=0;i<len;i++){
        if(cmd[i]=='A'){
            temp=v[0];
            v.erase(v.begin());
            v.push_back(temp);
        }else if(cmd[i]=='B'){
            temp=v[1];
            v.erase(v.begin()+1);
            v.push_back(temp);
        }
    }
    printf("%d %d %d\n",v[k-1],v[k],v[k+1]);
    return 0;
}
