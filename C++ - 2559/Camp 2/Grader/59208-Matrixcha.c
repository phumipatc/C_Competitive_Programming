#include<bits/stdc++.h>
using namespace std;
int mic[50][50],a[50],b[50],n,att[50][50];
int play(int st,int en){
    if(mic[st][en])
        return mic[st][en];
    if(st==en)
        return 0;
    mic[st][en]=1<<25;
    int i;
    for(i=st;i<en;i++){
        if(play(st,i)+play(i+1,en)+a[st]*b[i]*b[en]<mic[st][en]){
            mic[st][en]=play(st,i)+play(i+1,en)+a[st]*b[i]*b[en];
            att[st][en]=i;
        }
    }
    return mic[st][en];
}
void print(int st,int en){
    if(st==en){
        printf("A%d",st);
        return ;
    }
    printf("(");
    print(st,att[st][en]);
    printf(" x ");
    print(att[st][en]+1,en);
    printf(")");
}
int main()
{
    int i,ans;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d %d",&a[i],&b[i]);
    ans=play(1,n);
    printf("%d\n",ans);
    print(1,n);
    return 0;
}
