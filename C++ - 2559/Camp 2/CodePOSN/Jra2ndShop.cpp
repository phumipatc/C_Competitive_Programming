#include<bits/stdc++.h>
using namespace std;
struct A
{
    int num[21];
    int number;
    bool operator<(const A & B) const
    {
        if(number < B.number)
            return true;
        else if(number > B.number)
            return false;
        else {
        for(int i=0;i<20;i++){
            if(num[i] < B.num[i])
                return true;
            else if(num[i] > B.num[i])
                return false;
            else
                continue;
        }
        }
    }
};
A A[400000];
int temp[21];
vector<int>a[10];
int mark[10],Num;
void DFS(int now,int state)
{
    temp[state] = now;
    if(state!=0&&now == 2)
    {
        for(int i=0;i<=state;i++)
            A[Num].num[i] = temp[i];
        A[Num].number = state;
        Num++;
        return;
    }
    int siz = a[now].size();
    for(int i=0;i<siz;i++)
    {
        if(mark[a[now][i]]==0)
        {
            mark[a[now][i]] = 1;
            DFS(a[now][i],state+1);
            mark[a[now][i]] = 0;
        }
    }
}
int main()
{
    int m;
    scanf("%d ",&m);
    while(m--)
    {
        int A,b;
        scanf("%d %d",&A,&b);
        a[A].push_back(b);
        a[b].push_back(A);
    }
    DFS(2,0);
    sort(A,A+Num);
    //printf("%d\n",Num);
    for(int i=0;i<Num;i++)
    {
        for(int j=0;A[i].num[j]!=0;j++)
            printf("%d",A[i].num[j]);
        cout << endl;
    }
    return 0;
}
