#include <cstdio>
#include <queue>
using namespace std;
struct B{
    int i,j,fromi,fromj;
};
typedef struct B B;
char a[200][200];
int d[200][200][2],e[200][200];
queue< B > q;
B temp;
int main(){
    int r,c,i,j,si,sj,ei,ej,nowi,nowj,nexti,nextj;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++){
    for(j=0;j<c;j++){
        scanf(" %c",&a[i][j]);
        if(a[i][j]=='S'){
                si=i,sj=j;
            temp.i=i,temp.j=j;  temp.fromi=-1,temp.fromj=-1;
            q.push(temp);   e[i][j]=1;
        }
        else if(a[i][j]=='E')
            ei=i,ej=j;
        }
    }
    while(!q.empty()){
        nowi=q.front().i;   nowj=q.front().j;
        d[nowi][nowj][0]=q.front().fromi, d[nowi][nowj][1]=q.front().fromj;
        if(nowi==ei && nowj==ej)    break;
        q.pop();

        nexti = (nowi==0)? r-1 : nowi-1;
        nextj = nowj;
        if(a[nexti][nextj]!='#' && e[nexti][nextj]!=1){
            e[nexti][nextj]=1;
            temp.i=nexti,temp.j=nextj, temp.fromi=nowi, temp.fromj=nowj;
            q.push(temp);
        }
        nexti = (nowi==r-1)? 0 : nowi+1;
        nextj = nowj;
        if(a[nexti][nextj]!='#' && e[nexti][nextj]!=1){
            e[nexti][nextj]=1;
            temp.i=nexti,temp.j=nextj, temp.fromi=nowi, temp.fromj=nowj;
            q.push(temp);
        }
        nexti = nowi;
        nextj = (nowj==0)? c-1 : nowj-1;
        if(a[nexti][nextj]!='#' && e[nexti][nextj]!=1){
            e[nexti][nextj]=1;
            temp.i=nexti,temp.j=nextj, temp.fromi=nowi, temp.fromj=nowj;
            q.push(temp);
        }
        nexti = nowi;
        nextj = (nowj==c-1)? 0 : nowj+1;
        if(a[nexti][nextj]!='#' && e[nexti][nextj]!=1){
            e[nexti][nextj]=1;
            temp.i=nexti,temp.j=nextj, temp.fromi=nowi, temp.fromj=nowj;
            q.push(temp);
        }
    }
    while( !(nowi==si&&nowj==sj)){
        i= d[nowi][nowj][0], j = d[nowi][nowj][1];
        a[i][j]='x';
        nowi=i,nowj=j;
    }
    a[si][sj]='S';
    for(i=0;i<r;i++)
        printf("%s\n",a[i]);
	return 0;
}
1:17

#include<algorithm>
#include<cstdio>
using namespace std;
long long a[30000];
int main(){
    int n,i;
    long long sum=0,ans,temp;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&a[i]);
        sum += a[i];
    }
    if(n == 1){
        printf("%lld\n",a[0]);  return 0;
    }
    sort(a,a+n);
    ans = sum*2,temp=sum;
    for(i=0;i<n-2;i++){
        temp -= a[i];
        ans += temp;
    }
    printf("%lld\n",ans);
    return 0;
}
