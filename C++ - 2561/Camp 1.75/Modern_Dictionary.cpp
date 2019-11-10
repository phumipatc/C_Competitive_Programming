/*
	Task    :
	Author  : Phumipat C.
	School  : RYW
	Language: C++
*/
#include<bits/stdc++.h>
using namespace std;
vector<int> g[30],ans;
int mark[30],in[30];
char a[110][20];
priority_queue<int> heap;
int main()
{
    int n,i,len,len2,j,u,v,now,ch = 0,cnt = 0;
    scanf("%d",&n);
    for(i=0; i<n; i++){
        scanf(" %s",a[i]);
        len = strlen(a[i]);
        for(j=0;j<len;j++)
            mark[a[i][j]-'a']=1;
    }
    for(i=0;i<n-1;i++){
        len = strlen(a[i]),len2 = strlen(a[i+1]);
        for(j=0;j<min(len,len2);j++){
            if(a[i][j]!=a[i+1][j]){
                u = a[i][j]-'a',v = a[i+1][j]-'a';
                g[u].push_back(v);
                in[v]++;
                break;
            }
        }
    }
    for(i=0;i<26;i++)
        if(in[i] == 0 && mark[i] == 1)
            heap.push(i);
    while(!heap.empty()){
        now = heap.top();
        heap.pop();
        if(!heap.empty())   ch = 1;
        ans.push_back(now);
        for(auto x: g[now]){
            in[x]--;
            if(in[x] == 0)
                heap.push(x);
        }
    }
    for(i=0;i<26;i++)
        if(mark[i])
            cnt++;
    if(ans.size()!=cnt) printf("!");
    else if(ch)         printf("?");
    else{
        for(i=0;i<ans.size();i++)
            printf("%c",ans[i]+'a');
    }
    return 0;
}
/*
3 jaja baba baja
3
man tan fan
5
ula uka klua kula al
*/
