/*
    TASK :
    AUTHOR : Tanapoom Laoaron
    SCHOOL : RYW
    LANG : CPP
*/
#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<int,int> PII;
char str[1050],respond[1050];
vector<int> ans;
vector< pair<PII,PII> > bfs[2];
int main(){
    int q,qq,i,j,k,n,b,f,l,r,mid,ll,rr,ch;
    scanf(" %d",&q);
    for(qq=1;qq<=q;qq++){
        scanf(" %d %d %d",&n,&b,&f);
        for(i=0;i<n;i++){
            str[i]='0'+(i/16)%2;
        }
        printf("%s\n",str);
        fflush(stdout);
        scanf("%s",respond);
        if(respond[0]=='-');
        int last=0;
        for(i=0;i<n;i+=16){
            for(j=last;j<n-b&&respond[last]==respond[j];j++);
            if(j==last){
                for(j=i;j<n;j++) ans.push_back(j);
            }else{
                bfs[0].push_back({{i,min(i+15,n-1)},{last,j-1}});
                last=j;
            }
        }
        for(i=1;i<5;i++){
//            for(j=0;j<ans.size();j++) printf("%d ",ans[j]);
//            printf("\n");
            int a=(i&1)^1,b=i&1;
            if(bfs[a].empty()) break;
            bfs[b].clear();
            for(j=0;j<bfs[a].size();j++){
                l = bfs[a][j].x.x;
                r = bfs[a][j].x.y;
                mid = (l+r)>>1;
                for(k=l;k<=r;k++) str[k]='0'+(k>mid);
            }
            printf("%s\n",str);
            fflush(stdout);
            scanf("%s",respond);
            if(respond[0]=='-') return 0;
            for(j=0;j<bfs[a].size();j++){
                l = bfs[a][j].x.x;
                r = bfs[a][j].x.y;
                ll = bfs[a][j].y.x;
                rr = bfs[a][j].y.y;
                mid = (l+r)>>1;
                ch = rr+1;
                for(k=ll;k<=rr;k++){
                    if(respond[k]=='1'){
                        ch=k; break;
                    }
                }
                if(ch==ll){
                    for(k=l;k<=mid;k++) ans.push_back(k);
                    if(mid+1!=r) bfs[b].push_back({ {mid+1,r} , {ch,rr} });
                }else if(ch==rr+1){
                    for(k=mid+1;k<=r;k++) ans.push_back(k);
                    if(l!=mid) bfs[b].push_back({ {l,mid} , {ll,ch-1} });
                }else{
                    if(l!=mid) bfs[b].push_back({ {l,mid} , {ll,ch-1} });
                    if(mid+1!=r) bfs[b].push_back({ {mid+1,r} , {ch,rr} });
                }
            }
        }
//        printf("hooray!\n");
        assert((int)ans.size()==b);
        sort(ans.begin(),ans.end());
        for(i=0;i<b;i++) printf("%d ",ans[i]);
        printf("\n");
        fflush(stdout);
        ans.clear();
        int verdict;
        scanf("%d",&verdict);
        if(verdict==-1) return 0;
        bfs[0].clear();
        bfs[1].clear();
        memset(str,0,sizeof str);
        memset(respond,0,sizeof respond);
    }
    return 0;
}
