#include<bits/stdc++.h>
using namespace std;
char tmp[120][20];
vector<int>a[50];
int ch[50],in[50],Ans,Num;
int ans[50],num;
priority_queue<int>q;
int main()
{
    int m;
    scanf("%d",&m);
    for(int i=0; i<m; i++)
        scanf(" %s",tmp[i]);
    int len = strlen(tmp[0]);
    for(int i=0; i<len; i++){
        if(ch[tmp[0][i]-'a'] == 0)
            ch[tmp[0][i]-'a'] = 1,Ans++;
    }
    for(int j=1; j<m; j++){
        int lena = strlen(tmp[j-1]);
        int lenb = strlen(tmp[j]);
        int cha  = 1;
        for(int i=0; i<max(lena,lenb); i++){
            if(i<lenb&&ch[tmp[j][i]-'a']==0)
                ch[tmp[j][i]-'a']=1,Ans++;
            if(cha&&i<min(lena,lenb)&&tmp[j-1][i]!=tmp[j][i]){
                cha = 0;
                a[tmp[j-1][i]-'a'].push_back(tmp[j][i]-'a');
                in[tmp[j][i]-'a']++;
            }
        }
    }
    int Che = 0;
    for(int i=0; i<30; i++){
        if(ch[i])   Num++;
        if(ch[i] && in[i] == 0 && a[i].size()>0)
            Che++,q.push(-i);
    }
    if(Che == 0){
        printf("!\n");
        return 0;
    }
    else if(Che > 1){
        printf("?\n");
        return 0;
    }
    while(!q.empty()){
        int now = -q.top();
        int siz = a[now].size();
        q.pop();
        Che = 0;
        ans[num] = now;
        num++;
        for(int i=0; i<siz; i++){
            in[a[now][i]]--;
            if(in[a[now][i]]==0)
                q.push(-a[now][i]),Che++;
        }
        if(Che == 0 && Num!=num){
        printf("!\n");
        return 0;
        }
        if(Che > 1){
            printf("?\n");
            return 0;
        }
    }
    if(!q.empty()){
        printf("!\n");
        return 0;
    }
    if(num!=Num){
        printf("?\n");
        return 0;
    }
    for(int i=0; i<num; i++)
        printf("%c",ans[i]+'a');
    return 0;
}
